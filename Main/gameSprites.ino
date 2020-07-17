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

  displayWordWon(15,5);
}

// ----------------------------------------------------------------------
// ----------------------------- WORD DISPLAYING SPRITES ----------------
// ----------------------------------------------------------------------

void displaySnakeWord(byte startingLine, byte startingColumn) {
  const static byte PROGMEM snakeLogo[5][20] = {
    {1,1,1,0,1,0,0,1,0,1,1,1,0,1,0,1,0,1,1,1},
    {1,0,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0},
    {1,1,1,0,1,0,1,1,0,1,1,1,0,1,1,0,0,1,1,1},
    {0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0},
    {1,1,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,1,1}
  };

  for(byte i = 0; i < 5; i++) {
    for(byte j = 0; j < 20; j++) {
      LEDMatrix[startingLine+i][startingColumn+j] = pgm_read_word(&snakeLogo[i][j]);
    }
  }
}

void displayWordBlue(byte startingLine, byte startingColumn) {
  const static byte PROGMEM wordBlue[5][15] = {
    {2,2,2,0,2,0,0,0,2,0,2,0,2,2,2},
    {2,0,2,0,2,0,0,0,2,0,2,0,2,0,0},
    {2,2,2,0,2,0,0,0,2,0,2,0,2,2,2},
    {2,0,2,0,2,0,0,0,2,0,2,0,2,0,0},
    {2,2,2,0,2,2,2,0,2,2,2,0,2,2,2}
  };

  for(byte i = 0; i < 5; i++) {
    for(byte j = 0; j < 15; j++) {
      LEDMatrix[startingLine+i][startingColumn+j] = pgm_read_word(&wordBlue[i][j]);
    }
  }
}

void displayWordRed(byte startingLine, byte startingColumn) {
  const static byte PROGMEM wordRed[5][11] = {
    {3,3,3,0,3,3,3,0,3,3,0},
    {3,0,3,0,3,0,0,0,3,0,3},
    {3,3,3,0,3,3,3,0,3,0,3},
    {3,3,0,0,3,0,0,0,3,0,3},
    {3,0,3,0,3,3,3,0,3,3,0}
  };

  for(byte i = 0; i < 5; i++) {
    for(byte j = 0; j < 11; j++) {
      LEDMatrix[startingLine+i][startingColumn+j] = pgm_read_word(&wordRed[i][j]);
    }
  }
}

void displayWordYellow(byte startingLine, byte startingColumn) {
  const static byte PROGMEM wordYellow[5][25] = {
    {8,0,8,0,8,8,8,0,8,0,0,0,8,0,0,0,8,8,8,0,8,0,0,0,8},
    {8,0,8,0,8,0,0,0,8,0,0,0,8,0,0,0,8,0,8,0,8,0,0,0,8},
    {0,8,0,0,8,8,8,0,8,0,0,0,8,0,0,0,8,0,8,0,8,0,8,0,8},
    {0,8,0,0,8,0,0,0,8,0,0,0,8,0,0,0,8,0,8,0,8,0,8,0,8},
    {0,8,0,0,8,8,8,0,8,8,8,0,8,8,8,0,8,8,8,0,8,8,8,8,8}
  };

  for(byte i = 0; i < 5; i++) {
    for(byte j = 0; j < 25; j++) {
      LEDMatrix[startingLine+i][startingColumn+j] = pgm_read_word(&wordYellow[i][j]);
    }
  }
}

void displayWordGreen (byte startingLine, byte startingColumn) {
  const static byte PROGMEM wordGreen[5][20] = {
    {4,4,4,0,4,4,4,0,4,4,4,0,4,4,4,0,4,0,0,4},
    {4,0,0,0,4,0,4,0,4,0,0,0,4,0,0,0,4,4,0,4},
    {4,0,4,0,4,4,4,0,4,4,4,0,4,4,4,0,4,0,4,4},
    {4,0,4,0,4,4,0,0,4,0,0,0,4,0,0,0,4,0,0,4},
    {4,4,4,0,4,0,4,0,4,4,4,0,4,4,4,0,4,0,0,4}
  };

  for(byte i = 0; i < 5; i++) {
    for(byte j = 0; j < 20; j++) {
      LEDMatrix[startingLine+i][startingColumn+j] = pgm_read_word(&wordGreen[i][j]);
    }
  }
}

void displayWordPurple (byte startingLine, byte startingColumn) {
  const static byte PROGMEM wordPurple[5][23] = {
    {5,5,5,0,5,0,5,0,5,5,5,0,5,5,5,0,5,0,0,0,5,5,5},
    {5,0,5,0,5,0,5,0,5,0,5,0,5,0,5,0,5,0,0,0,5,0,0},
    {5,5,5,0,5,0,5,0,5,0,5,0,5,5,5,0,5,0,0,0,5,5,5},
    {5,0,0,0,5,0,5,0,5,5,0,0,5,0,0,0,5,0,0,0,5,0,0},
    {5,0,0,0,5,5,5,0,5,0,5,0,5,0,0,0,5,5,5,0,5,5,5}
  };

  for(byte i = 0; i < 5; i++) {
    for(byte j = 0; j < 23; j++) {
      LEDMatrix[startingLine+i][startingColumn+j] = pgm_read_word(&wordPurple[i][j]);
    }
  }
}

void displayWordWon (byte startingLine, byte startingColumn) {
  const static byte PROGMEM wordWon[5][17] = {
    {1,0,0,0,1,0,1,1,1,0,1,0,0,1,0,0,1},
    {1,0,0,0,1,0,1,0,1,0,1,1,0,1,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0},
    {1,1,1,1,1,0,1,1,1,0,1,0,0,1,0,0,1}
  };

  for(byte i = 0; i < 5; i++) {
    for(byte j = 0; j < 17; j++) {
      LEDMatrix[startingLine+i][startingColumn+j] = pgm_read_word(&wordWon[i][j]);
    }
  }
}

// ----------------------------------------------------------------------
// ----------------------------- SHAPES DISPLAYING SPRITES --------------
// ----------------------------------------------------------------------

void displayShapeSnakeOne (byte startingLine, byte startingColumn) {
  const static byte PROGMEM snakeOne[5][3] = {
    {1,1,1},
    {1,0,0},
    {1,1,0},
    {0,1,0},
    {0,1,0}
  };

  for(byte i = 0; i < 5; i++) {
    for(byte j = 0; j < 3; j++) {
      LEDMatrix[startingLine+i][startingColumn+j] = pgm_read_word(&snakeOne[i][j]);
    }
  }
}

void displayShapeSnakeTwo (byte startingLine, byte startingColumn) {
  const static byte PROGMEM snakeTwo[5][3] = {
    {1,1,0},
    {0,1,0},
    {0,1,1},
    {0,0,1},
    {0,0,1}
  };

  for(byte i = 0; i < 5; i++) {
    for(byte j = 0; j < 3; j++) {
      LEDMatrix[startingLine+i][startingColumn+j] = pgm_read_word(&snakeTwo[i][j]);
    }
  }
}

void displayShapeSnakeThree (byte startingLine, byte startingColumn) {
  const static byte PROGMEM snakeThree[5][3] = {
   {1,0,0},
   {1,0,0},
   {1,1,0},
   {0,1,0},
   {1,1,0}
  };

  for(byte i = 0; i < 5; i++) {
    for(byte j = 0; j < 3; j++) {
      LEDMatrix[startingLine+i][startingColumn+j] = pgm_read_word(&snakeThree[i][j]);
    }
  }
}

void displayShapeSnakeFour (byte startingLine, byte startingColumn) {
  const static byte PROGMEM snakeFour[5][3] = {
   { 1,1,0},
   {1,0,0},
   {1,1,1},
   {0,0,1},
   {0,0,1}
  };

  for(byte i = 0; i < 5; i++) {
    for(byte j = 0; j < 3; j++) {
      LEDMatrix[startingLine+i][startingColumn+j] = pgm_read_word(&snakeFour[i][j]);
    }
  }
}

void displayShapeSnakeWest (byte startingLine, byte startingColumn) {
   const static byte PROGMEM snakeWest[15][3] = {
    {0,1,1},
    {0,0,1},
    {0,0,1},
    {0,0,1},
    {0,0,1},
    {0,0,1},
    {1,1,1},
    {1,0,0},
    {1,0,0},
    {1,0,0},
    {1,0,0},
    {1,0,0},
    {1,0,0},
    {1,0,0},
    {1,1,1}
  };

  for(byte i = 0; i < 15; i++) {
    for(byte j = 0; j < 3; j++) {
      LEDMatrix[startingLine+i][startingColumn+j] = pgm_read_word(&snakeWest[i][j]);
    }
  }
}
    
  
