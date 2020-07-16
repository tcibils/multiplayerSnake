void generateApple(const byte replacedAppleID) {
  const byte appleLineNumber = random(totalDisplayNumberOfRows);
  const byte appleColumnNumber = random (totalDisplayNumberOfColumns);
  /*
  Serial.print("The apple will be in ");
  Serial.print("{");
  Serial.print(appleLineNumber);
  Serial.print(", ");
  Serial.print(appleColumnNumber);
  Serial.print("}. \n");
  */
  // And we set the apple to the coordinates created
  apples[replacedAppleID] = {appleLineNumber, appleColumnNumber};

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
}

void displayAllApples() {
  for(byte displayAppleID = 0; displayAppleID < numberOfApples; displayAppleID++) {
    LEDMatrix[apples[displayAppleID].applePosition.lineCoordinate][apples[displayAppleID].applePosition.columnCoordinate] = apples[displayAppleID].colour;
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
  for(byte appleIndex=0; appleIndex < numberOfApples; appleIndex++) {
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
    
    if(players[playerID].newBodyPosition[0].columnCoordinate == apples[appleIndex].applePosition.columnCoordinate && players[playerID].newBodyPosition[0].lineCoordinate == apples[appleIndex].applePosition.lineCoordinate) {
      // In which case, we set the apple caught parameter of this player to 1
       players[playerID].appleCaught = 1;
       // And we generate a new apple straight away
       generateApple(appleIndex);
    }
  }
}
