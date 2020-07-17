/* 
 *  Creator : Thomas Cibils
 *  FastLED tuto : https://github.com/FastLED/FastLED/wiki/Basic-usage - used for WS2812B 5050 RGB LED Strip 5M 150 300 Leds 144 60LED/M Individual Addressable 5V
 *  */

#include <TimerOne.h>
#include "FastLED.h"
#include <avr/pgmspace.h>

/* TODO
 *  
 *  - Manage time decrease
 *  - Maybe add a white frame around the table or something to show the boundaries?
 *  - Experiment with more or less apples
 *  - Make "snake" word froms tart slightly glow, Aurore found that cool
 *  - Add little fireworks in the win screen
 *  - Have different speed per player, with a tradeoff speed vs long snake ???
 */


// ----------------------------------------------------------------------------------------------------
// ----------------------------------   LED MATRIX CODE   ---------------------------------------------
// ----------------------------------------------------------------------------------------------------

// This marix is actually composed of four distinct 16x16 LED matrices. Constant below mirror that.

// Total number of LEDs
#define totalDisplayNumberOfRows 32                          // Number of rows
#define totalDisplayNumberOfColumns 32                       // Number of coumns
#define TOTAL_NUM_LEDS totalDisplayNumberOfRows * totalDisplayNumberOfColumns // Number of LEDs

// Number of LEDs by display
#define quantityOfSingleMatrixDisplay 4
#define singleMatrixDisplayNumberOfRows 16
#define singleMatrixDisplayNumberOfColumns 16
#define SINGLE_NUM_LEDS singleMatrixDisplayNumberOfRows * singleMatrixDisplayNumberOfColumns

// And here are the displays.
CRGB leds[quantityOfSingleMatrixDisplay][SINGLE_NUM_LEDS];

// And their respective data pins
#define LEDSONE_DATA_PIN 2       // Top left
#define LEDSTWO_DATA_PIN 3       // Top right
#define LEDSTHREE_DATA_PIN 4     // Bottom left
#define LEDSFOUR_DATA_PIN 5      // Bottom right

// On the other hand, here is our updatable digital LED Matrix
byte LEDMatrix[totalDisplayNumberOfRows][totalDisplayNumberOfColumns];

// Original colours for leds.
const byte Black = 0;
const byte White = 1;
const byte Blue = 2;
const byte Red = 3;
const byte Green = 4;
const byte Purple = 5;
const byte LightBlue = 6;
const byte Pink = 7;
const byte Orange = 8;
const byte Yellow = 9;
const byte LightPurple = 10;



// ----------------------------------------------------------------------------------------------------
// -------------------------------   SNES CONTROLLERS CODE   ------------------------------------------
// ----------------------------------------------------------------------------------------------------


#define NUMBER_PLAYERS 4

// PIN Mapping for each controller

// P1 is on the vent side
static const byte CONTROLLER_ONE_PIN_LATCH = 40;
static const byte CONTROLLER_ONE_PIN_CLOCK = 42;
static const byte CONTROLLER_ONE_PIN_DATA = 44;

// P2 is on the USB side
static const byte CONTROLLER_TWO_PIN_LATCH = 41;
static const byte CONTROLLER_TWO_PIN_CLOCK = 43;
static const byte CONTROLLER_TWO_PIN_DATA = 45;

// Etc
static const byte CONTROLLER_THREE_PIN_LATCH = 48;
static const byte CONTROLLER_THREE_PIN_CLOCK = 50;
static const byte CONTROLLER_THREE_PIN_DATA = 52;

static const byte CONTROLLER_FOUR_PIN_LATCH = 49;
static const byte CONTROLLER_FOUR_PIN_CLOCK = 51;
static const byte CONTROLLER_FOUR_PIN_DATA = 53;

// Table storing which player is pushing which buttons, so it can easily be accessed anywhere in the code (there are 12 buttons)
// Stored as follows: UP - RIGHT - DOWN - LEFT - START - SELECT - A - B - X - Y - L - R
byte playerButtonPushed[NUMBER_PLAYERS][12] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};


// ----------------------------------------------------------------------------------------------------
// -----------------------------------------   SPRITES   ----------------------------------------------
// ----------------------------------------------------------------------------------------------------





// ----------------------------------------------------------------------------------------------------
// -------------------------------------   GAME PARAMETERS   ------------------------------------------
// ----------------------------------------------------------------------------------------------------
// Defines the maximum size of a snake. 
// Should be equal or lower than 255, as iterators on body size are "byte" type !
// Should be bigger or equal to 30, due to mock snake sprites
#define maxSnakeSize 40             

#define directionUp 0
#define directionRight 1
#define directionDown 2
#define directionLeft 3

#define directionNorth 4
#define directionEast 5
#define directionSouth 6
#define directionWest 7

#define moveSpeed 100                 // In miliseconds. Can be used to make something happen every X miliseconds.
#define initialPlayerMovingSpeed 200  // Base speed of all players, in miliseconds
#define playerMovingSpeedDecrease 20  // How quickly will the player speed improve if eating a quickening apple
#define mapIsWalled 0                 // If 1, then the map is a square, and hitting a wall kills you. If 0, then you can go through map borders to get on the other side. Only option 0 is implemented so far.
#define numberOfApples 4              // Defines how many apples are present in the game
#define deadPlayersRemain 0           // If 0, then dead players are erased from the map. If 1, then they remain displayed. Currently, only 0 is implemented.
#define chancesOfSpeedyApple 30       // chances, in percentage, that an apple is one that speeds the player

#define initialPositionLinePlayerOne 0
#define initialPositionColumnPlayerOne 0

#define initialPositionLinePlayerTwo 0
#define initialPositionColumnPlayerTwo 31

#define initialPositionLinePlayerThree 31
#define initialPositionColumnPlayerThree 0

#define initialPositionLinePlayerFour 31
#define initialPositionColumnPlayerFour 31

// ----------------------------------------------------------------------------------------------------
// -------------------------------------   OTHER TECHNICALS   -----------------------------------------
// ----------------------------------------------------------------------------------------------------

// Useful struct
struct pointOnMatrix {
  byte lineCoordinate;
  byte columnCoordinate;
};

struct Player {
  pointOnMatrix bodyPosition[maxSnakeSize];
  pointOnMatrix newBodyPosition[maxSnakeSize];
  byte headColour;
  byte colour;
  byte goingDirection;
  byte appleCaught;                               // 1 means normalapple eaten, 0 means no, 2 means speeding apple eaten
  byte isAlive;                                   // 1 means alive, 0 means dead
  byte isActive;                                  // 1 means that the player is actually playing, 0 means that he isn't
  unsigned int movingSpeed;                       // Speed at which the player will move
};


// This is use for player colour selection only.
struct MockPlayer {
  pointOnMatrix bodyPosition[maxSnakeSize];
  pointOnMatrix newBodyPosition[maxSnakeSize];
  byte headColour;
  byte colour;
};


struct Apple {
  pointOnMatrix applePosition;
  byte colour;
  byte appleType;                         // 1 means "making the snake longer", 2 means "make the snake faster"
};

Apple apples[numberOfApples];             // Contains the apples
Player players[NUMBER_PLAYERS];           // Contains the players
MockPlayer mockPlayers[NUMBER_PLAYERS];
unsigned int applesEaten = 0;             // Counts how many apples were eaten in total

/*
Contains the game status.
 - 0 means the game is starting with welcome screen and all
 - 1 means that the game is running,
 - 2 means that we're showing the end-game screen or something
*/

byte gameState = 0;     
byte winningPlayer = 5; // This will store the player who won                 

unsigned long lastMillis = 0;

void setup() {

  Serial.begin(9600);

  // Set the four matrix pins to output
  FastLED.addLeds<NEOPIXEL, LEDSONE_DATA_PIN>(leds[0], SINGLE_NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, LEDSTWO_DATA_PIN>(leds[1], SINGLE_NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, LEDSTHREE_DATA_PIN>(leds[2], SINGLE_NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, LEDSFOUR_DATA_PIN>(leds[3], SINGLE_NUM_LEDS);

  // Sets the controllers as inputs or outputs
  pinMode(CONTROLLER_ONE_PIN_LATCH, OUTPUT);
  pinMode(CONTROLLER_ONE_PIN_CLOCK, OUTPUT);
  pinMode(CONTROLLER_ONE_PIN_DATA, INPUT); 
  
  pinMode(CONTROLLER_TWO_PIN_LATCH, OUTPUT);
  pinMode(CONTROLLER_TWO_PIN_CLOCK, OUTPUT);
  pinMode(CONTROLLER_TWO_PIN_DATA, INPUT); 
  
  pinMode(CONTROLLER_THREE_PIN_LATCH, OUTPUT);
  pinMode(CONTROLLER_THREE_PIN_CLOCK, OUTPUT);
  pinMode(CONTROLLER_THREE_PIN_DATA, INPUT); 
  
  pinMode(CONTROLLER_FOUR_PIN_LATCH, OUTPUT);
  pinMode(CONTROLLER_FOUR_PIN_CLOCK, OUTPUT);
  pinMode(CONTROLLER_FOUR_PIN_DATA, INPUT); 

  // Set basic player values
  
  defineMockSnakesInitialColour();
  defineMockSnakesZeroPositions();
  defineMockSnakesOnePositions();
  defineMockSnakesTwoPositions();
  defineMockSnakesThreePositions();
  
  initializeApples(numberOfApples);

  // By default, all players aren't active
  for(byte i = 0; i < NUMBER_PLAYERS; i++) {
    players[i].isActive = 0;
  }
}

void loop() {
  
  if (millis() - lastMillis >= moveSpeed) {
    checkAllButtons();
    
    // If we're in the pre-launch screen
    if(gameState == 0) {
      clearLEDMatrix();
      expectStartingGame();
      startPage();
      // Call playerChoices() to define active players
    }

    // If we're playing the game
    if(gameState == 1) {
      clearLEDMatrix();
      // It gets played
      changeAllPlayerDirections();
      displayAllApples();
      moveAllPlayers();
      displayAllPlayerSnakes();
      checkIfAPlayerWon();
    }

    if(gameState == 2) {
      clearLEDMatrix();
      displayWinningMessage(winningPlayer);
      expectStartingGame();
    }

    outputDisplay();
    lastMillis = millis();
  }
  delay(1);
}
