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
  // Copy snake in previousSnake, with 1 of difference
  // Add as first dot the point in which the player is going
  // Check if the player dies
  // If the player ate an apple, keep the last place of the snake body
  if(players[playerID].goingDirection == directionNorth) {
    
  }
}
