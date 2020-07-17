void changeAllPlayerDirections() {
  checkAllButtons();
  for(byte playerIndex=0; playerIndex < NUMBER_PLAYERS; playerIndex++) {
    if(players[playerIndex].isActive == 1) {
      changePlayerDirection(playerIndex);
    }
  }
}

void changePlayerDirection(const byte playerID) {
  // Each player is placed on a different side of the table
  // Hence, their perspective on the snake going "left" or "right" is different
  if(playerID == 0) {     
    if(playerButtonPushed[0][0] == 1) {
      // We want to avoid the snake going back on itself
      if(players[0].goingDirection != directionSouth) {
        players[0].goingDirection = directionNorth;
      }
    }
    if(playerButtonPushed[0][1] == 1) {
      if(players[0].goingDirection != directionWest) {
        players[0].goingDirection = directionEast;
      }
    }
    if(playerButtonPushed[0][2] == 1) {
      if(players[0].goingDirection != directionNorth) {
        players[0].goingDirection = directionSouth;
      }
    }
    if(playerButtonPushed[0][3] == 1) {
      if(players[0].goingDirection != directionEast) {
        players[0].goingDirection = directionWest;
      }
    }
  }

  if(playerID == 1) {
    if(playerButtonPushed[1][0] == 1) {
      if(players[1].goingDirection != directionEast) {
      players[1].goingDirection = directionWest;
      }
    }
    if(playerButtonPushed[1][1] == 1) {
      if(players[1].goingDirection != directionSouth) {
      players[1].goingDirection = directionNorth;
      }
    }
    if(playerButtonPushed[1][2] == 1) {
      if(players[1].goingDirection != directionWest) {
      players[1].goingDirection = directionEast;
      }
    }
    if(playerButtonPushed[1][3] == 1) {
      if(players[1].goingDirection != directionNorth) {
      players[1].goingDirection = directionSouth;
      }
    }
  }

  if(playerID == 2) {
    if(playerButtonPushed[2][0] == 1) {
      if(players[2].goingDirection != directionSouth) {
      players[2].goingDirection = directionNorth;
      }
    }
    if(playerButtonPushed[2][1] == 1) {
      if(players[2].goingDirection != directionWest) {
      players[2].goingDirection = directionEast;
      }
    }
    if(playerButtonPushed[2][2] == 1) {
      if(players[2].goingDirection != directionNorth) {
      players[2].goingDirection = directionSouth;
      }
    }
    if(playerButtonPushed[2][3] == 1) {
      if(players[2].goingDirection != directionEast) {
      players[2].goingDirection = directionWest;
      }
    }
  }

  if(playerID == 3) {
    if(playerButtonPushed[3][0] == 1) {
      if(players[3].goingDirection != directionWest) {
      players[3].goingDirection = directionEast;
      }
    }
    if(playerButtonPushed[3][1] == 1) {
      if(players[3].goingDirection != directionNorth) {
      players[3].goingDirection = directionSouth;
      }
    }
    if(playerButtonPushed[3][2] == 1) {
      if(players[3].goingDirection != directionEast) {
      players[3].goingDirection = directionWest;
      }
    }
    if(playerButtonPushed[3][3] == 1) {
      if(players[3].goingDirection != directionSouth) {
      players[3].goingDirection = directionNorth;
      }
    }
  }
}

void moveAllPlayers() {
  for(byte playerIndex=0; playerIndex < NUMBER_PLAYERS; playerIndex++) {
    if(players[playerIndex].isActive == 1) {
      movePlayer(playerIndex);
    }
  }
}

// Checks if player "playerID" has hit any player's snake body, including life/death logic of the players
void checkIfPlayerDied(const byte playerID) {
  // We only make the check if the player we're talking about isn't dead already
  if(players[playerID].isAlive == 1) {
    // we check if we've hit any player
    for(byte playerIndex=0; playerIndex < NUMBER_PLAYERS; playerIndex++) {
      if(players[playerIndex].isActive == 1) {
        // If we're erasing dead players,
        if(deadPlayersRemain == 0) {
          // Then we check that we haven't hit an alive player
          if(players[playerIndex].isAlive == 1) {
            checkIfPlayerHeadHitSnake(playerID, playerIndex);
          }
        }
        // If dead players can be hit
        else if(deadPlayersRemain == 1) {
            checkIfPlayerHeadHitSnake(playerID, playerIndex);
        }
      }
    }
  }
}

// checks if the head of player "playerID" has hit the body of player "playerIndex", without life/death logic of the players
void checkIfPlayerHeadHitSnake(const byte playerID, const byte playerIndex) {
  if(players[playerID].isActive == 1 && players[playerIndex].isActive == 1) {
    // We iterate on each snake body
    for (int snakeBodyIterator = 0; snakeBodyIterator < maxSnakeSize; snakeBodyIterator++) {
  //    Serial.print("Snake body iterator: ");
  //    Serial.print(snakeBodyIterator);
  //    Serial.print("\n");
      // If we're iterating and finding the actual player, and we're considering the snake head
      if(playerID == playerIndex &&  snakeBodyIterator == 0) {
        // Then we do nothing, as we don't want the snake's head to hit itself
      }
      // If we're iterating on anything else - and we want the snake to be able to hit its own body !
      else {
        // If the head of the snake is on the same position as one of the body parts, we end the game.
        // In the direction changes, there is some logic to avoid the player to get back on itself
        if(players[playerIndex].bodyPosition[snakeBodyIterator].lineCoordinate != 255 && players[playerIndex].bodyPosition[snakeBodyIterator].columnCoordinate!= 255) {
          if (players[playerID].newBodyPosition[0].lineCoordinate == players[playerIndex].bodyPosition[snakeBodyIterator].lineCoordinate && players[playerID].newBodyPosition[0].columnCoordinate == players[playerIndex].bodyPosition[snakeBodyIterator].columnCoordinate) {
            players[playerID].isAlive = 0;
            /*
              Serial.print("playerID :");
              Serial.print(playerID);
              Serial.print(" is now ");
              Serial.print(players[playerID].isAlive);
              Serial.print(", because his head, in (");
              Serial.print(players[playerID].newBodyPosition[0].lineCoordinate);
              Serial.print(", ");
              Serial.print(players[playerID].newBodyPosition[0].columnCoordinate);
              Serial.print(") hit player ");
              Serial.print(playerIndex);
              Serial.print(" body part number ");
              Serial.print(snakeBodyIterator);
              Serial.print(" which is in (");
              Serial.print(players[playerIndex].bodyPosition[snakeBodyIterator].lineCoordinate);
              Serial.print(", ");
              Serial.print(players[playerIndex].bodyPosition[snakeBodyIterator].columnCoordinate);
              Serial.print("). \n");
            */
          }
        }
      }
    }
  }
}


void checkIfAnyPlayerDied() {
  for(byte playerIndex=0; playerIndex < NUMBER_PLAYERS; playerIndex++) {
    if(players[playerIndex].isActive == 1) {
      checkIfPlayerDied(playerIndex);
    }
  }
}

void movePlayer(const byte playerID) {

  if (millis() - lastMillis < moveSpeed) {
 //   Serial.print("Time interval too short. Snake not moved \n");
  }


  // If enough time has passed,
  if (millis() - lastMillis >= moveSpeed) {
      
    // First, move the snake head
    // if we're going up,
    if(players[playerID].goingDirection == directionNorth) {
    
      // and if we're already at the top of the matrix,
      if(players[playerID].bodyPosition[0].lineCoordinate == 0) {
        if(mapIsWalled == 0) {
          // then we go to the bottom of the matrix.
          players[playerID].newBodyPosition[0].lineCoordinate = totalDisplayNumberOfRows-1;
        }
      }
      else {
        players[playerID].newBodyPosition[0].lineCoordinate = players[playerID].bodyPosition[0].lineCoordinate - 1;
      }
      // And the column coordinate doesn't change.
      players[playerID].newBodyPosition[0].columnCoordinate = players[playerID].bodyPosition[0].columnCoordinate;
    }
    
  
    // Now if we're going right,
    else if(players[playerID].goingDirection == directionEast) {
      // If we're not already at the right end of the matrix
      if(players[playerID].bodyPosition[0].columnCoordinate < totalDisplayNumberOfColumns-1) {
        if(mapIsWalled == 0) {
          // we simply avance the head of one column, hence to the right. 
          players[playerID].newBodyPosition[0].columnCoordinate = players[playerID].bodyPosition[0].columnCoordinate + 1;
        }
      }
      // But if we're on the last column on the right end of the matrix,
      else {
        // we set the column coordinate of the head of the snake to the first colum (on the left end) of the matrix.
        players[playerID].newBodyPosition[0].columnCoordinate = 0;
      }
      // And the line coordinate doesn't change
      players[playerID].newBodyPosition[0].lineCoordinate = players[playerID].bodyPosition[0].lineCoordinate;
    }

    
    // Now if we're going south,
    else if(players[playerID].goingDirection == directionSouth) {
      // If we're already at the bottom of the matrix
      if(players[playerID].bodyPosition[0].lineCoordinate == totalDisplayNumberOfRows-1) {
        if(mapIsWalled == 0) {
          // Then we get to the matrix top
          players[playerID].newBodyPosition[0].lineCoordinate = 0;
        }
      }
      // And if we're not at the bottom
      else {
        // Then we simply increase the line by 1 to go south
        players[playerID].newBodyPosition[0].lineCoordinate = players[playerID].bodyPosition[0].lineCoordinate + 1;
      }
      
      players[playerID].newBodyPosition[0].columnCoordinate = players[playerID].bodyPosition[0].columnCoordinate;
    }

    // Now if we're going west
    else if(players[playerID].goingDirection == directionWest) {
      // If we're already at the total left of the matirx
      if(players[playerID].bodyPosition[0].columnCoordinate == 0) {
        if(mapIsWalled == 0) {
          // Then we get to the other side of the matrix
          players[playerID].newBodyPosition[0].columnCoordinate = totalDisplayNumberOfColumns-1;
        }
      }
      // If we're not yet at the total left
      else {
        // Then we simply decrease the column coordinate by 1 to go south
        players[playerID].newBodyPosition[0].columnCoordinate = players[playerID].bodyPosition[0].columnCoordinate - 1;
      }
      // And the line coordinate doesn't change
      players[playerID].newBodyPosition[0].lineCoordinate = players[playerID].bodyPosition[0].lineCoordinate;
    }
  
    // Checking if an apple was eaten or if the player died
    checkIfAppleEatedAllPlayers();
    checkIfAnyPlayerDied();
  
    // We copy the previous snake in the new snake
    for(byte playerBodyIndex = 0; playerBodyIndex < maxSnakeSize - 1; playerBodyIndex++) {


      players[playerID].newBodyPosition[playerBodyIndex + 1].lineCoordinate = players[playerID].bodyPosition[playerBodyIndex].lineCoordinate;
      players[playerID].newBodyPosition[playerBodyIndex + 1].columnCoordinate = players[playerID].bodyPosition[playerBodyIndex].columnCoordinate;
  

    
      // If we reached the end of the snake body
      if(players[playerID].bodyPosition[playerBodyIndex].lineCoordinate == 255 || players[playerID].bodyPosition[playerBodyIndex].columnCoordinate == 255) {
        // And if the player did not caught the apple
        if(players[playerID].appleCaught == 0) {
          // Then the new snake should have the last bite of the previous snake erased
          players[playerID].newBodyPosition[playerBodyIndex].lineCoordinate = 255;
          players[playerID].newBodyPosition[playerBodyIndex].columnCoordinate = 255;
        }
      }
    }

    // If the apple was caught, it did its job of making the snake longer, and thus we reset the parameter.
    if(players[playerID].appleCaught == 1) {
      players[playerID].appleCaught = 0;
    }
  
    // And finally we copy the new snake in the old snake back
    for(byte playerBodyIndex = 0; playerBodyIndex < maxSnakeSize; playerBodyIndex++) {
      players[playerID].bodyPosition[playerBodyIndex].lineCoordinate = players[playerID].newBodyPosition[playerBodyIndex].lineCoordinate;
      players[playerID].bodyPosition[playerBodyIndex].columnCoordinate = players[playerID].newBodyPosition[playerBodyIndex].columnCoordinate;    
    }
  }
}

// Takes a snake, and displays it on the matrix, regardless of the player's status
void displaySnake(const byte playerID) {
  // Then we iterate on the player's snake body, to plot it on the LED Matrix.
  for(byte playerBodyIndex = 0; playerBodyIndex < maxSnakeSize; playerBodyIndex++) {
    // If we didn't reach the snake's end
    if(players[playerID].bodyPosition[playerBodyIndex].lineCoordinate != 255 && players[playerID].bodyPosition[playerBodyIndex].columnCoordinate != 255) {
      // We add the player snake position to the matrix
      if(playerBodyIndex == 0) {
        LEDMatrix[players[playerID].bodyPosition[playerBodyIndex].lineCoordinate][players[playerID].bodyPosition[playerBodyIndex].columnCoordinate] = players[playerID].headColour;
      }
      else {
        LEDMatrix[players[playerID].bodyPosition[playerBodyIndex].lineCoordinate][players[playerID].bodyPosition[playerBodyIndex].columnCoordinate] = players[playerID].colour;
      }
    }
  }
}
  
// Displays a player's snake on the LEDMatrix, depending if he's alive or dead
void displayPlayerSnake(const byte playerID) {
  if(players[playerID].isActive == 1) {
    // If we do not show dead players
    if(deadPlayersRemain == 0) {
      // And if the player is alive
      if(players[playerID].isAlive == 1) {
        // We display the snake
          displaySnake(playerID);
      }
    }
    // If dead players remain, then we keep on displaying all snakes, dead or alive
    else if(deadPlayersRemain == 1) {
            // We display the snake
        displaySnake(playerID);
      }    
  }  
}



void displayAllPlayerSnakes() {
  for(byte playerIndex=0; playerIndex < NUMBER_PLAYERS; playerIndex++) {
    if(players[playerIndex].isActive == 1) {
      displayPlayerSnake(playerIndex);
    }
  }
}

void digitalOutputPlayer(const byte playerID) {
  Serial.print("Outputing for player ");
  Serial.print(playerID);
  Serial.print(": \n");
  Serial.print("Is active: ");
  Serial.print(players[playerID].isActive);
  Serial.print("\n");
  Serial.print("Head colour: ");
  Serial.print(players[playerID].headColour);
  Serial.print("\n");
  Serial.print("Colour: ");
  Serial.print(players[playerID].colour);
  Serial.print("\n");
  Serial.print("is alive: ");
  Serial.print(players[playerID].isAlive);
  Serial.print("\n");
  Serial.print("has caught an apple: ");
  Serial.print(players[playerID].appleCaught);
  Serial.print("\n");
  Serial.print("Body position: ");
  for(byte i = 0; i < maxSnakeSize; i++) {
    if(players[playerID].bodyPosition[i].lineCoordinate != 255) {
      Serial.print("(");
      Serial.print(players[playerID].bodyPosition[i].lineCoordinate);
      Serial.print("; ");
      Serial.print(players[playerID].bodyPosition[i].columnCoordinate);
      Serial.print("), ");
    }
  }
  Serial.print("\n");
  
  Serial.print("NewBody position: ");
  for(byte i = 0; i < maxSnakeSize; i++) {
    if(players[playerID].newBodyPosition[i].lineCoordinate != 255) {
      Serial.print("(");
      Serial.print(players[playerID].newBodyPosition[i].lineCoordinate);
      Serial.print("; ");
      Serial.print(players[playerID].newBodyPosition[i].columnCoordinate);
      Serial.print("), ");
    }
  }
  Serial.print("\n");
}
  
