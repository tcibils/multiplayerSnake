void initializeGame() {
  initializePlayers(NUMBER_PLAYERS);
  initializeApples(numberOfApples);
}

void initializeApples(const byte quantityOfApples) {
  apples[0].applePosition.lineCoordinate = 9;
  apples[0].applePosition.columnCoordinate = 9;
  apples[0].colour = Green;
  
  apples[1].applePosition.lineCoordinate = 9;
  apples[1].applePosition.columnCoordinate = 22;
  apples[1].colour = Green;
  
  apples[2].applePosition.lineCoordinate = 22;
  apples[2].applePosition.columnCoordinate = 9;
  apples[2].colour = Green;
  
  apples[3].applePosition.lineCoordinate = 22;
  apples[3].applePosition.columnCoordinate = 22;
  apples[3].colour = Green;
  
}

// Reset player data based on pre-defined constants
// Quantity of players should allow us to control how many players to deal with, but that's currently not the case
void initializePlayers(const byte quantityOfPlayers) {
    players[0].bodyPosition[0].lineCoordinate = initialPositionLinePlayerOne;
    players[0].bodyPosition[0].columnCoordinate = initialPositionColumnPlayerOne;
    players[0].newBodyPosition[0].lineCoordinate = initialPositionLinePlayerOne;
    players[0].newBodyPosition[0].columnCoordinate = initialPositionColumnPlayerOne;
    players[0].goingDirection = directionEast;
    players[0].headColour = Blue;
    players[0].colour = LightBlue;
    
    
    players[1].bodyPosition[0].lineCoordinate = initialPositionLinePlayerTwo;
    players[1].bodyPosition[0].columnCoordinate = initialPositionColumnPlayerTwo;
    players[1].newBodyPosition[0].lineCoordinate = initialPositionLinePlayerTwo;
    players[1].newBodyPosition[0].columnCoordinate = initialPositionColumnPlayerTwo;
    players[1].goingDirection = directionSouth;
    players[1].headColour = Red;
    players[1].colour = Pink;
    
    players[2].bodyPosition[0].lineCoordinate = initialPositionLinePlayerThree;
    players[2].bodyPosition[0].columnCoordinate = initialPositionColumnPlayerThree;
    players[2].newBodyPosition[0].lineCoordinate = initialPositionLinePlayerThree;
    players[2].newBodyPosition[0].columnCoordinate = initialPositionColumnPlayerThree;
    players[2].goingDirection = directionNorth;
    players[2].headColour = Purple;
    players[2].colour = LightPurple;
    
    players[3].bodyPosition[0].lineCoordinate = initialPositionLinePlayerFour;
    players[3].bodyPosition[0].columnCoordinate = initialPositionColumnPlayerFour;
    players[3].newBodyPosition[0].lineCoordinate = initialPositionLinePlayerFour;
    players[3].newBodyPosition[0].columnCoordinate = initialPositionColumnPlayerFour;
    players[3].goingDirection = directionWest;
    players[3].headColour = Orange;
    players[3].colour = Yellow;

    for(byte playerIndex = 0; playerIndex < quantityOfPlayers; playerIndex++) {
      players[playerIndex].appleCaught = 0;
      players[playerIndex].isAlive = 1;
      for(byte bodyIndex = 1; bodyIndex < maxSnakeSize; bodyIndex++) {
        players[playerIndex].bodyPosition[bodyIndex].lineCoordinate = 255;
        players[playerIndex].bodyPosition[bodyIndex].columnCoordinate = 255;
        players[playerIndex].newBodyPosition[bodyIndex].lineCoordinate = 255;
        players[playerIndex].newBodyPosition[bodyIndex].columnCoordinate = 255;
      }
    }
}

void checkIfAPlayerWon() {
  if(players[0].isAlive == 1 &&
     players[1].isAlive == 0 &&
     players[2].isAlive == 0 &&
     players[3].isAlive == 0) {
      gameState = 2;
      winningPlayer = 0;
   }
     
  if(players[0].isAlive == 0 &&
     players[1].isAlive == 1 &&
     players[2].isAlive == 0 &&
     players[3].isAlive == 0) {
      gameState = 2;
      winningPlayer = 1;
   }
     
  if(players[0].isAlive == 0 &&
     players[1].isAlive == 0 &&
     players[2].isAlive == 1 &&
     players[3].isAlive == 0) {
      gameState = 2;
      winningPlayer = 2;
   }
     
  if(players[0].isAlive == 0 &&
     players[1].isAlive == 0 &&
     players[2].isAlive == 0 &&
     players[3].isAlive == 1) {
      gameState = 2;
      winningPlayer = 3;
   }
}

void displayWinningMessage(const byte playerID) {
  
  if(players[playerID].headColour == Blue) {
    displayWordBlue(5,5);
  }

  if(players[playerID].headColour == Red) {
    displayWordRed(5,5);
  }

  if(players[playerID].headColour == Green) {
    displayWordGreen(5,5);
  }

  if(players[playerID].headColour == Yellow || players[playerID].headColour == Orange) {
    displayWordYellow(5,5);
  }

  if(players[playerID].headColour == Purple) {
    displayWordPurple(5,5);
  }

  displayWordWon(15,15);
}

void expectStartingGame() {
  // If any player
  for(byte indexPlayer = 0; indexPlayer < NUMBER_PLAYERS; indexPlayer++) {
    // Is pressing start button
    if(playerButtonPushed[indexPlayer][4] == 1) {
      // Then we start the game
      gameState = 1;
    }
  }
}
