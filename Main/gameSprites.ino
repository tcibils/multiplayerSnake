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
    for(byte j = 0; j < 20; j++) {
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
    for(byte j = 0; j < 20; j++) {
      LEDMatrix[startingLine+i][startingColumn+j] = pgm_read_word(&wordRed[i][j]);
    }
  }
}

void displayWordYellow(byte startingLine, byte startingColumn) {
  const static byte PROGMEM wordYellow[5][25] = {
    {9,0,9,0,9,9,9,0,9,0,0,0,9,0,0,0,9,9,9,0,9,0,0,0,9},
    {9,0,9,0,9,0,0,0,9,0,0,0,9,0,0,0,9,0,9,0,9,0,0,0,9},
    {0,9,0,0,9,9,9,0,9,0,0,0,9,0,0,0,9,0,9,0,9,0,9,0,9},
    {0,9,0,0,9,0,0,0,9,0,0,0,9,0,0,0,9,0,9,0,9,0,9,0,9},
    {0,9,0,0,9,9,9,0,9,9,9,0,9,9,9,0,9,9,9,0,9,9,9,9,9}
  };

  for(byte i = 0; i < 5; i++) {
    for(byte j = 0; j < 20; j++) {
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
    for(byte j = 0; j < 20; j++) {
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
    for(byte j = 0; j < 20; j++) {
      LEDMatrix[startingLine+i][startingColumn+j] = pgm_read_word(&wordWon[i][j]);
    }
  }
}
