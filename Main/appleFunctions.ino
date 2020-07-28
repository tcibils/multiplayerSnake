void initializeApples() {

  // We setup data for all apples anyway

  apples[0].applePosition.lineCoordinate = 9;
  apples[0].applePosition.columnCoordinate = 9;
  apples[0].colour = White;
  apples[0].appleType = 1;
  
  if(players[0].isActive == 1) {apples[0].isActive = 1;}
  else                         {apples[0].isActive = 0;}
  
  apples[1].applePosition.lineCoordinate = 9;
  apples[1].applePosition.columnCoordinate = 22;
  apples[1].colour = White;
  apples[1].appleType = 1;  

  if(players[1].isActive == 1) {apples[1].isActive = 1;}
  else                         {apples[1].isActive = 0;}

  apples[2].applePosition.lineCoordinate = 22;
  apples[2].applePosition.columnCoordinate = 9;
  apples[2].colour = White;
  apples[2].appleType = 1;
  
  if(players[2].isActive == 1) {apples[2].isActive = 1;}
  else                         {apples[2].isActive = 0;}

  apples[3].applePosition.lineCoordinate = 22;
  apples[3].applePosition.columnCoordinate = 22;
  apples[3].colour = White;
  apples[3].appleType = 1;
  
  if(players[3].isActive == 1) {apples[3].isActive = 1;}
  else                         {apples[3].isActive = 0;}

}

void generateApple(const byte replacedAppleID) {
  const byte appleLineNumber = random(totalDisplayNumberOfRows);
  const byte appleColumnNumber = random (totalDisplayNumberOfColumns);
  const byte randomNumberForAppleType = random(100);
  /*
  Serial.print("The apple will be in ");
  Serial.print("{");
  Serial.print(appleLineNumber);
  Serial.print(", ");
  Serial.print(appleColumnNumber);
  Serial.print("}. \n");
  */
  // And we set the apple to the coordinates created
  apples[replacedAppleID].applePosition.lineCoordinate = appleLineNumber;
  apples[replacedAppleID].applePosition.columnCoordinate = appleColumnNumber;

  if(randomNumberForAppleType < chancesOfSpeedyApple) {
    apples[replacedAppleID].appleType = 2;
    apples[replacedAppleID].colour = Purple;
  }
  else {
    apples[replacedAppleID].appleType = 1;
    apples[replacedAppleID].colour = White;
  }

  // We check that the apple didn't appear on the snake.
  // We scan the whole grid
  for (int i = 0; i < maxSnakeSize; i++) {
    // and if the apple drops on any snake
    for(int snakeID = 0; snakeID < NUMBER_PLAYERS; snakeID++) {
      if (apples[replacedAppleID].applePosition.lineCoordinate == players[snakeID].bodyPosition[i].lineCoordinate && apples[replacedAppleID].applePosition.columnCoordinate == players[snakeID].bodyPosition[i].columnCoordinate) {
        // We re-create a new apple, hopefully somewhere else - in the worst case, we will again generate a new one.
        generateApple(replacedAppleID);
        // Serial.print("But the snake was already there, so we re-generate an apple. \n");
  
      }
    }
  }
  // Also, if the apple was spawned in an obstacle
  if(Obstacles[apples[replacedAppleID].applePosition.lineCoordinate][apples[replacedAppleID].applePosition.columnCoordinate] > 0) {
    // We re-generate a new apple, hopefully somewhere else
    generateApple(replacedAppleID);
  }
  
}

void displayAllApples() {
  for(byte displayAppleID = 0; displayAppleID < maxNumberOfApples; displayAppleID++) {
    if(apples[displayAppleID].isActive == 1) {
      LEDMatrix[apples[displayAppleID].applePosition.lineCoordinate][apples[displayAppleID].applePosition.columnCoordinate] = apples[displayAppleID].colour;
    }
  }
}

void checkIfAppleEatedAllPlayers() {
  
  for(byte playerIndex=0; playerIndex < NUMBER_PLAYERS; playerIndex++) {
    checkIfAppleEated(playerIndex);
  }
}

void checkIfAppleEated(const byte playerID) {
  /*
  Serial.print("Called for playerID ");
  Serial.print(playerID);
  Serial.print("\n");
  */
  // for a given player, for each apple
  for(byte appleIndex=0; appleIndex < maxNumberOfApples; appleIndex++) {
    // We check if the snake head is on the apple
    /*
    Serial.print("For player ");
    Serial.print(playerID);
    Serial.print(", we check for apple ");
    Serial.print(appleIndex);
    Serial.print("\n");
    Serial.print("players[playerID].newBodyPosition[0].columnCoordinate: ");
    Serial.print(players[playerID].newBodyPosition[0].columnCoordinate);
    Serial.print(" = ");
    Serial.print(apples[appleIndex].columnCoordinate);
    Serial.print(" :apples[appleIndex].columnCoordinate");
    Serial.print("\n");
    Serial.print("players[playerID].newBodyPosition[0].lineCoordinate: ");
    Serial.print(players[playerID].newBodyPosition[0].lineCoordinate);
    Serial.print(" = ");
    Serial.print(apples[appleIndex].lineCoordinate);
    Serial.print(" :apples[appleIndex].lineCoordinate");
    Serial.print("\n");
    Serial.print("\n");
    */
    if(apples[appleIndex].isActive == 1) {
      if(players[playerID].newBodyPosition[0].columnCoordinate == apples[appleIndex].applePosition.columnCoordinate && players[playerID].newBodyPosition[0].lineCoordinate == apples[appleIndex].applePosition.lineCoordinate) {
        // In which case, we set the apple caught parameter of this player to 1 if the apple is a "normal one"
        // And set parameter to 2 if the apple is a speeding one
         players[playerID].appleCaught = apples[appleIndex].appleType;
         // And we generate a new apple straight away
         generateApple(appleIndex);
      }
    }
  }
}

void digitalOutputApple(const byte appleID) {
  Serial.print("Outputing for apple ");
  Serial.print(appleID);
  Serial.print(": \n");
  Serial.print("Apple position: (");
  Serial.print(apples[appleID].applePosition.lineCoordinate);
  Serial.print("; ");
  Serial.print(apples[appleID].applePosition.columnCoordinate);
  Serial.print(") \n");
  Serial.print("Colour: ");
  Serial.print(apples[appleID].colour);
  Serial.print("\n");
  Serial.print("IsActive: ");
  Serial.print(apples[appleID].isActive);
  Serial.print("\n");
}
