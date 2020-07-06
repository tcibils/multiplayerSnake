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
  if(players[playerID].goingDirection == directionNorth) {
    
  }
}
