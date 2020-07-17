void initializeGame() {
  initializePlayers();
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
void initializePlayers() {
  players[0].isActive = 1;
  players[1].isActive = 0;
  players[2].isActive = 1;
  players[3].isActive = 0;
  
  if(players[0].isActive == 1) {
    players[0].bodyPosition[0].lineCoordinate = initialPositionLinePlayerOne;
    players[0].bodyPosition[0].columnCoordinate = initialPositionColumnPlayerOne;
    players[0].newBodyPosition[0].lineCoordinate = initialPositionLinePlayerOne;
    players[0].newBodyPosition[0].columnCoordinate = initialPositionColumnPlayerOne;
    players[0].goingDirection = directionEast;
    players[0].headColour = Blue;
    players[0].colour = LightBlue;
    players[0].appleCaught = 0;
    players[0].isAlive = 1;
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
    players[1].headColour = Red;
    players[1].colour = Pink;
    players[1].appleCaught = 0;
    players[1].isAlive = 1;
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
    players[2].headColour = Purple;
    players[2].colour = LightPurple;
    players[2].appleCaught = 0;
    players[2].isAlive = 1;
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
    players[3].headColour = Orange;
    players[3].colour = Yellow;
    players[3].appleCaught = 0;
    players[3].isAlive = 1;
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

void displayStartPage() {
  displaySnakeWord(5,5);
  displayShapeSnakeOne(15, 5);
  displayShapeSnakeTwo(15, 10);
  displayShapeSnakeThree(15, 15);
  displayShapeSnakeFour(15, 20);
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
    }
  }
}
