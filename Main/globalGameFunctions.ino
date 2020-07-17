void initializeGame() {
  initializePlayers();
  initializeApples(numberOfApples);
}



// While the game state is 0, that function manages the starting page
void startPage() {
  // It displays the word "snake", centered
  displaySnakeWord(13,7);

  // It display the 4 mock snakes around, using their colours and placement
  displayMockSnake(0);
  displayMockSnake(1);
  displayMockSnake(2);
  displayMockSnake(3);

  // It keeps player choices open for colours and game-entering
  playersChoices();

  // And finally, if a player presses start, then the game starts
  expectStartingGame();
}

void playersChoices() {

  for(byte playerIndex = 0; playerIndex < NUMBER_PLAYERS; playerIndex++) {
    // Player 0 pushing button 6 (A), which is red
    if(playerButtonPushed[playerIndex][6] == 1) {
      players[playerIndex].isActive = 1;
      players[playerIndex].headColour = Red;
      players[playerIndex].colour = Pink;
      mockPlayers[playerIndex].headColour = Red;
      mockPlayers[playerIndex].colour = Pink;
    }
        // Player 0 pushing button 7 (B), which is yellow
    if(playerButtonPushed[playerIndex][7] == 1) {
      players[playerIndex].isActive = 1;
      players[playerIndex].headColour = Orange;
      players[playerIndex].colour = Yellow;
      mockPlayers[playerIndex].headColour = Orange;
      mockPlayers[playerIndex].colour = Yellow;
      
    }
        // Player 0 pushing button 9 (Y), which is green
    if(playerButtonPushed[playerIndex][9] == 1) {
      players[playerIndex].isActive = 1;
      players[playerIndex].headColour = Green;
      players[playerIndex].colour = Green;
      mockPlayers[playerIndex].headColour = Green;
      mockPlayers[playerIndex].colour = Green;
      
    }
        // Player 0 pushing button 8 (X), which is blue
    if(playerButtonPushed[playerIndex][8] == 1) {
      players[playerIndex].isActive = 1;
      players[playerIndex].headColour = Blue;
      players[playerIndex].colour = LightBlue;
      mockPlayers[playerIndex].headColour = Blue;
      mockPlayers[playerIndex].colour = LightBlue;
      
    }

     // Player 0 pushing button 10 and 11 (L and R), secret coulour !
     if(playerButtonPushed[playerIndex][11] == 1 && playerButtonPushed[playerIndex][10] == 1) {
      players[playerIndex].isActive = 1;
      players[playerIndex].headColour = Purple;
      players[playerIndex].colour = LightPurple;
      mockPlayers[playerIndex].headColour = Purple;
      mockPlayers[playerIndex].colour = LightPurple;
    }

    // Player 0 pushing button 5 (Select)
    if(playerButtonPushed[playerIndex][5] == 1) {
      players[playerIndex].isActive = 0;
      players[playerIndex].headColour = White;
      players[playerIndex].colour = White;
      mockPlayers[playerIndex].headColour = White;
      mockPlayers[playerIndex].colour = White;
      
    }
  }

  // Use a global "available colour" arrow to let the player chose only available colour
  // And all this is until an active player clicks on start, in which case the game starts with a gamestate change
}

void displayMockSnake(const byte playerID) {
  // We iterate on the player's snake body, to plot it on the LED Matrix.
  for(byte playerBodyIndex = 0; playerBodyIndex < maxSnakeSize; playerBodyIndex++) {
    // If we didn't reach the snake's end
    if(mockPlayers[playerID].bodyPosition[playerBodyIndex].lineCoordinate != 255 && mockPlayers[playerID].bodyPosition[playerBodyIndex].columnCoordinate != 255) {
      // We add the player snake position to the matrix
      if(playerBodyIndex == 0) {
        LEDMatrix[mockPlayers[playerID].bodyPosition[playerBodyIndex].lineCoordinate][mockPlayers[playerID].bodyPosition[playerBodyIndex].columnCoordinate] = mockPlayers[playerID].headColour;
      }
      else {
        LEDMatrix[mockPlayers[playerID].bodyPosition[playerBodyIndex].lineCoordinate][mockPlayers[playerID].bodyPosition[playerBodyIndex].columnCoordinate] = mockPlayers[playerID].colour;
      }
    }
  }
}

// Reset player data based on pre-defined constants
void initializePlayers() {
  
  if(players[0].isActive == 1) {
    players[0].bodyPosition[0].lineCoordinate = initialPositionLinePlayerOne;
    players[0].bodyPosition[0].columnCoordinate = initialPositionColumnPlayerOne;
    players[0].newBodyPosition[0].lineCoordinate = initialPositionLinePlayerOne;
    players[0].newBodyPosition[0].columnCoordinate = initialPositionColumnPlayerOne;
    players[0].goingDirection = directionEast;
    players[0].appleCaught = 0;
    players[0].isAlive = 1;
    players[0].movingSpeed = initialPlayerMovingSpeed;
    for(byte bodyIndex = 1; bodyIndex < maxSnakeSize; bodyIndex++) {
      players[0].bodyPosition[bodyIndex].lineCoordinate = 255;
      players[0].bodyPosition[bodyIndex].columnCoordinate = 255;
      players[0].newBodyPosition[bodyIndex].lineCoordinate = 255;
      players[0].newBodyPosition[bodyIndex].columnCoordinate = 255;
    }
  }
  else {
    players[0].bodyPosition[0].lineCoordinate = 255;
    players[0].bodyPosition[0].columnCoordinate = 255;
    players[0].newBodyPosition[0].lineCoordinate = 255;
    players[0].newBodyPosition[0].columnCoordinate = 255;
    players[0].goingDirection = directionEast;
    players[0].headColour = White;
    players[0].colour = White;
    players[0].appleCaught = 0;
    players[0].isAlive = 0;
    players[0].movingSpeed = initialPlayerMovingSpeed;
    for(byte bodyIndex = 1; bodyIndex < maxSnakeSize; bodyIndex++) {
      players[0].bodyPosition[bodyIndex].lineCoordinate = 255;
      players[0].bodyPosition[bodyIndex].columnCoordinate = 255;
      players[0].newBodyPosition[bodyIndex].lineCoordinate = 255;
      players[0].newBodyPosition[bodyIndex].columnCoordinate = 255;
    }
  }
    
  if(players[1].isActive == 1) {
    players[1].bodyPosition[0].lineCoordinate = initialPositionLinePlayerTwo;
    players[1].bodyPosition[0].columnCoordinate = initialPositionColumnPlayerTwo;
    players[1].newBodyPosition[0].lineCoordinate = initialPositionLinePlayerTwo;
    players[1].newBodyPosition[0].columnCoordinate = initialPositionColumnPlayerTwo;
    players[1].goingDirection = directionSouth;
    players[1].appleCaught = 0;
    players[1].isAlive = 1;
    players[1].movingSpeed = initialPlayerMovingSpeed;
    for(byte bodyIndex = 1; bodyIndex < maxSnakeSize; bodyIndex++) {
      players[1].bodyPosition[bodyIndex].lineCoordinate = 255;
      players[1].bodyPosition[bodyIndex].columnCoordinate = 255;
      players[1].newBodyPosition[bodyIndex].lineCoordinate = 255;
      players[1].newBodyPosition[bodyIndex].columnCoordinate = 255;
    }
  }
  else {
    players[1].bodyPosition[0].lineCoordinate = 255;
    players[1].bodyPosition[0].columnCoordinate = 255;
    players[1].newBodyPosition[0].lineCoordinate = 255;
    players[1].newBodyPosition[0].columnCoordinate = 255;
    players[1].goingDirection = directionSouth;
    players[1].headColour = White;
    players[1].colour = White;
    players[1].appleCaught = 0;
    players[1].isAlive = 0;
    players[1].movingSpeed = initialPlayerMovingSpeed;
    for(byte bodyIndex = 1; bodyIndex < maxSnakeSize; bodyIndex++) {
      players[1].bodyPosition[bodyIndex].lineCoordinate = 255;
      players[1].bodyPosition[bodyIndex].columnCoordinate = 255;
      players[1].newBodyPosition[bodyIndex].lineCoordinate = 255;
      players[1].newBodyPosition[bodyIndex].columnCoordinate = 255;
    }
  }
  
  if(players[2].isActive == 1) {
    players[2].bodyPosition[0].lineCoordinate = initialPositionLinePlayerThree;
    players[2].bodyPosition[0].columnCoordinate = initialPositionColumnPlayerThree;
    players[2].newBodyPosition[0].lineCoordinate = initialPositionLinePlayerThree;
    players[2].newBodyPosition[0].columnCoordinate = initialPositionColumnPlayerThree;
    players[2].goingDirection = directionNorth;
    players[2].appleCaught = 0;
    players[2].isAlive = 1;
    players[2].movingSpeed = initialPlayerMovingSpeed;
    for(byte bodyIndex = 1; bodyIndex < maxSnakeSize; bodyIndex++) {
      players[2].bodyPosition[bodyIndex].lineCoordinate = 255;
      players[2].bodyPosition[bodyIndex].columnCoordinate = 255;
      players[2].newBodyPosition[bodyIndex].lineCoordinate = 255;
      players[2].newBodyPosition[bodyIndex].columnCoordinate = 255;
    }
  }
  else {
    players[2].bodyPosition[0].lineCoordinate = 255;
    players[2].bodyPosition[0].columnCoordinate = 255;
    players[2].newBodyPosition[0].lineCoordinate = 255;
    players[2].newBodyPosition[0].columnCoordinate = 255;
    players[2].goingDirection = directionNorth;
    players[2].headColour = White;
    players[2].colour = White;
    players[2].appleCaught = 0;
    players[2].isAlive = 0;
    players[2].movingSpeed = initialPlayerMovingSpeed;
    for(byte bodyIndex = 1; bodyIndex < maxSnakeSize; bodyIndex++) {
      players[2].bodyPosition[bodyIndex].lineCoordinate = 255;
      players[2].bodyPosition[bodyIndex].columnCoordinate = 255;
      players[2].newBodyPosition[bodyIndex].lineCoordinate = 255;
      players[2].newBodyPosition[bodyIndex].columnCoordinate = 255;
    }
  }
    
  if(players[3].isActive == 1) {
    players[3].bodyPosition[0].lineCoordinate = initialPositionLinePlayerFour;
    players[3].bodyPosition[0].columnCoordinate = initialPositionColumnPlayerFour;
    players[3].newBodyPosition[0].lineCoordinate = initialPositionLinePlayerFour;
    players[3].newBodyPosition[0].columnCoordinate = initialPositionColumnPlayerFour;
    players[3].goingDirection = directionWest;
    players[3].appleCaught = 0;
    players[3].isAlive = 1;
    players[3].movingSpeed = initialPlayerMovingSpeed;
    for(byte bodyIndex = 1; bodyIndex < maxSnakeSize; bodyIndex++) {
      players[3].bodyPosition[bodyIndex].lineCoordinate = 255;
      players[3].bodyPosition[bodyIndex].columnCoordinate = 255;
      players[3].newBodyPosition[bodyIndex].lineCoordinate = 255;
      players[3].newBodyPosition[bodyIndex].columnCoordinate = 255;
    }
  }
  else {
    players[3].bodyPosition[0].lineCoordinate = 255;
    players[3].bodyPosition[0].columnCoordinate = 255;
    players[3].newBodyPosition[0].lineCoordinate = 255;
    players[3].newBodyPosition[0].columnCoordinate = 255;
    players[3].goingDirection = directionWest;
    players[3].headColour = White;
    players[3].colour = White;
    players[3].appleCaught = 0;
    players[3].isAlive = 0;    
    players[3].movingSpeed = initialPlayerMovingSpeed;
    for(byte bodyIndex = 1; bodyIndex < maxSnakeSize; bodyIndex++) {
      players[3].bodyPosition[bodyIndex].lineCoordinate = 255;
      players[3].bodyPosition[bodyIndex].columnCoordinate = 255;
      players[3].newBodyPosition[bodyIndex].lineCoordinate = 255;
      players[3].newBodyPosition[bodyIndex].columnCoordinate = 255;
    }
  }
}

void checkIfAPlayerWon() {
  if(players[0].isAlive == 1 && players[0].isActive == 1 &&
     players[1].isAlive == 0 &&
     players[2].isAlive == 0 &&
     players[3].isAlive == 0) {
      gameState = 2;
      winningPlayer = 0;
   }
     
  if(players[0].isAlive == 0 &&
     players[1].isAlive == 1 && players[1].isActive == 1 &&
     players[2].isAlive == 0 &&
     players[3].isAlive == 0) {
      gameState = 2;
      winningPlayer = 1;
   }
     
  if(players[0].isAlive == 0 &&
     players[1].isAlive == 0 &&
     players[2].isAlive == 1 && players[2].isActive == 1 &&
     players[3].isAlive == 0) {
      gameState = 2;
      winningPlayer = 2;
   }
     
  if(players[0].isAlive == 0 &&
     players[1].isAlive == 0 &&
     players[2].isAlive == 0 &&
     players[3].isAlive == 1 && players[3].isActive == 1) {
      gameState = 2;
      winningPlayer = 3;
   }
}

void expectStartingGame() {
  // If any player
  // Serial.print("we're expecting game start \n");
  for(byte indexPlayer = 0; indexPlayer < NUMBER_PLAYERS; indexPlayer++) {
    // Is pressing start button
    /*
    Serial.print("player ");
    Serial.print(indexPlayer);
    Serial.print(" button playerButtonPushed[indexPlayer][4]: ");
    Serial.print(playerButtonPushed[indexPlayer][4]);
    Serial.print("\n");
    */
    if(playerButtonPushed[indexPlayer][4] == 1) {
      // Then we start the game
      gameState = 1;
      initializePlayers();
    }
  }
}
