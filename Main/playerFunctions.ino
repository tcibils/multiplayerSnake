void changeAllPlayerDirections() {
  for(byte playerIndex=0; playerIndex < NUMBER_PLAYERS; playerIndex++) {
    changePlayerDirection(playerIndex);
  }
}

void changePlayerDirection(const byte playerID) {
  if(playerID == 0) {
    if(playerButtonPushed[0][0] == 1) {
      players[0].goingDirection = directionNorth;
    }
    if(playerButtonPushed[0][1] == 1) {
      players[0].goingDirection = directionEast;
    }
    if(playerButtonPushed[0][2] == 1) {
      players[0].goingDirection = directionSouth;
    }
    if(playerButtonPushed[0][3] == 1) {
      players[0].goingDirection = directionWest;
    }
  }

  if(playerID == 1) {
    // To be filled depending on how I built stuff
  }

  if(playerID == 2) {
    
  }

  if(playerID == 3) {
    
  }
}

void movePlayer(const byte playerID) {

  if (millis() - lastMillis < moveSpeed) {
 //   Serial.print("Time interval too short. Snake not moved \n");
  }


  // If enough time has passed,
  if (millis() - lastMillis >= moveSpeed) {
    
  }
  // Copy snake in previousSnake, with 1 of difference
  // Add as first dot the point in which the player is going
  // Check if the player dies
  // If the player ate an apple, keep the last place of the snake body

  // First, move the snake head
  
  // if we're going up,
  if(players[playerID].goingDirection == directionNorth) {
    // and if we're already at the top of the matrix,
    if(players[playerID].bodyPosition[0].lineCoordinate == 0) {
      if(mapIsWalled == 0) {
        // then we go to the bottom of the matrix.
        players[playerID].bodyPosition[0].lineCoordinate = totalDisplayNumberOfRows-1;
      }
    }
    else {
      players[playerID].bodyPosition[0].lineCoordinate -= 1;
    }
  }

  // Now if we're going right,
  else if(players[playerID].goingDirection == directionEast) {
    // If we're not already at the right end of the matrix
    if(players[playerID].bodyPosition[0].columnCoordinate < totalDisplayNumberOfColumns-1) {
      if(mapIsWalled == 0) {
        // we simply avance the head of one column, hence to the right. 
        players[playerID].bodyPosition[0].columnCoordinate += 1;
      }
    }
    // But if we're on the last column on the right end of the matrix,
    else {
      // we set the column coordinate of the head of the snake to the first colum (on the left end) of the matrix.
      players[playerID].bodyPosition[0].columnCoordinate = 0;
    }
  }

  else if(players[playerID].goingDirection == directionSouth) {
    if(players[playerID].bodyPosition[0].lineCoordinate == totalDisplayNumberOfRows-1) {
      if(mapIsWalled == 0) {
        players[playerID].bodyPosition[0].columnCoordinate = 0;
      }
    }
    else {
      players[playerID].bodyPosition[0].columnCoordinate += 1;
    }
  }

  else if(players[playerID].goingDirection == directionWest) {
    if(players[playerID].bodyPosition[0].columnCoordinate == 0) {
      if(mapIsWalled == 0) {
        players[playerID].bodyPosition[0].columnCoordinate = totalDisplayNumberOfColumns-1;
      }
    }
    else {
      players[playerID].bodyPosition[0].columnCoordinate -= 1;
    }
  }

  checkIfAppleEatedAllPlayers();
  
}



void checkIfPlayerDied(const byte playerID) {
  // we check if we've hit any player
  for(byte playerIndex=0; playerIndex < NUMBER_PLAYERS; playerIndex++) {
    // For each alive player
    if(players[playerID].isAlive == 1) {
      // ITERATOR STARTS AT 1 - THAT WAS MEANINGFULL FOR A SINGLE PLAYER SNAKE; NEEDS TO BE TWISTED HERE
      for (int snakeBodyIterator = 1; snakeBodyIterator < maxSnakeSize; snakeBodyIterator++) {
        // If the head of the snake is on the same position as one of the body parts, we end the game.
        if (players[playerID].bodyPosition[0].lineCoordinate == players[playerIndex].bodyPosition[snakeBodyIterator].lineCoordinate && players[playerID].bodyPosition[0].columnCoordinate == players[playerIndex].bodyPosition[snakeBodyIterator].columnCoordinate) {
          players[playerID].isAlive = 0;
        }
      }
    }
  }
}

void checkIfAnyPlayerDied() {
  for(byte playerIndex=0; playerIndex < NUMBER_PLAYERS; playerIndex++) {
    checkIfPlayerDied(playerIndex);
  }
}
