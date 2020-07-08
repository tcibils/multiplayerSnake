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
      if (apples[replacedAppleID].lineCoordinate == players[snakeID].bodyPosition[i].lineCoordinate && apples[replacedAppleID].columnCoordinate == players[snakeID].bodyPosition[i].columnCoordinate) {
        // We re-create a new apple, hopefully somewhere else - in the worst case, we will again generate a new one.
        generateApple(replacedAppleID);
        // Serial.print("But the snake was already there, so we re-generate an apple. \n");
  
      }
    }
  }
}

void checkIfAppleEatedAllPlayers() {
  for(byte playerIndex=0; playerIndex < NUMBER_PLAYERS; playerIndex++) {
    checkIfAppleEated(playerIndex);
  }
}

void checkIfAppleEated(const byte playerID) {
  // for a given player, for each apple
  for(byte appleID; appleID < numberOfApples; appleID++) {
    // We check if the snake head is on the apple
    if(players[playerID].bodyPosition[0].columnCoordinate == apples[appleID].columnCoordinate && players[playerID].bodyPosition[0].lineCoordinate == apples[appleID].lineCoordinate) {
      // In which case, we set the apple caught parameter of this player to 1
       players[playerID].appleCaught = 1;
       // And we generate a new apple straight away
       generateApple(appleID);
    }
  }
}
