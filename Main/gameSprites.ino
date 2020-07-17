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

void defineMockSnakesInitialColour() {
  mockPlayers[0].colour = White;
  mockPlayers[0].headColour = White;
  mockPlayers[1].colour = White;
  mockPlayers[1].headColour = White;
  mockPlayers[2].colour = White;
  mockPlayers[2].headColour = White;
  mockPlayers[3].colour = White;
  mockPlayers[3].headColour = White;
  
}

void defineMockSnakesZeroPositions() {
  mockPlayers[0].bodyPosition[0].lineCoordinate = 21;
  mockPlayers[0].bodyPosition[0].columnCoordinate = 24;
  
  mockPlayers[0].bodyPosition[1].lineCoordinate = 22;
  mockPlayers[0].bodyPosition[1].columnCoordinate = 24;
  
  mockPlayers[0].bodyPosition[2].lineCoordinate = 23;
  mockPlayers[0].bodyPosition[2].columnCoordinate = 24;
  
  mockPlayers[0].bodyPosition[3].lineCoordinate = 24;
  mockPlayers[0].bodyPosition[3].columnCoordinate = 24;
  
  mockPlayers[0].bodyPosition[4].lineCoordinate = 24;
  mockPlayers[0].bodyPosition[4].columnCoordinate = 23;
  
  mockPlayers[0].bodyPosition[5].lineCoordinate = 24;
  mockPlayers[0].bodyPosition[5].columnCoordinate = 22;
  
  mockPlayers[0].bodyPosition[6].lineCoordinate = 24;
  mockPlayers[0].bodyPosition[6].columnCoordinate = 21;
  
  mockPlayers[0].bodyPosition[7].lineCoordinate = 24;
  mockPlayers[0].bodyPosition[7].columnCoordinate = 20;
  
  mockPlayers[0].bodyPosition[8].lineCoordinate = 25;
  mockPlayers[0].bodyPosition[8].columnCoordinate = 20;
  
  mockPlayers[0].bodyPosition[9].lineCoordinate = 26;
  mockPlayers[0].bodyPosition[9].columnCoordinate = 20;
  
  mockPlayers[0].bodyPosition[10].lineCoordinate = 27;
  mockPlayers[0].bodyPosition[10].columnCoordinate = 20;
  
  mockPlayers[0].bodyPosition[11].lineCoordinate = 28;
  mockPlayers[0].bodyPosition[11].columnCoordinate = 20;
  
  mockPlayers[0].bodyPosition[12].lineCoordinate = 29;
  mockPlayers[0].bodyPosition[12].columnCoordinate = 20;
  
  mockPlayers[0].bodyPosition[13].lineCoordinate = 29;
  mockPlayers[0].bodyPosition[13].columnCoordinate = 19;
  
  mockPlayers[0].bodyPosition[14].lineCoordinate = 29;
  mockPlayers[0].bodyPosition[14].columnCoordinate = 18;
  
  mockPlayers[0].bodyPosition[15].lineCoordinate = 29;
  mockPlayers[0].bodyPosition[15].columnCoordinate = 17;
  
  mockPlayers[0].bodyPosition[16].lineCoordinate = 29;
  mockPlayers[0].bodyPosition[16].columnCoordinate = 16;
  
  mockPlayers[0].bodyPosition[17].lineCoordinate = 29;
  mockPlayers[0].bodyPosition[17].columnCoordinate = 15;
  
  mockPlayers[0].bodyPosition[18].lineCoordinate = 29;
  mockPlayers[0].bodyPosition[18].columnCoordinate = 14;
  
  mockPlayers[0].bodyPosition[19].lineCoordinate = 28;
  mockPlayers[0].bodyPosition[19].columnCoordinate = 14;
  
  mockPlayers[0].bodyPosition[20].lineCoordinate = 27;
  mockPlayers[0].bodyPosition[20].columnCoordinate = 14;
  
  mockPlayers[0].bodyPosition[21].lineCoordinate = 26;
  mockPlayers[0].bodyPosition[21].columnCoordinate = 14;
  
  mockPlayers[0].bodyPosition[22].lineCoordinate = 25;
  mockPlayers[0].bodyPosition[22].columnCoordinate = 14;

  mockPlayers[0].bodyPosition[23].lineCoordinate = 25;
  mockPlayers[0].bodyPosition[23].columnCoordinate = 13;
  
  mockPlayers[0].bodyPosition[24].lineCoordinate = 25;
  mockPlayers[0].bodyPosition[24].columnCoordinate = 12;
  
  mockPlayers[0].bodyPosition[25].lineCoordinate = 25;
  mockPlayers[0].bodyPosition[25].columnCoordinate = 11;
  
  mockPlayers[0].bodyPosition[26].lineCoordinate = 25;
  mockPlayers[0].bodyPosition[26].columnCoordinate = 10;

  for(byte i = 27; i<maxSnakeSize; i++) {
    mockPlayers[0].bodyPosition[i].lineCoordinate = 255;
    mockPlayers[0].bodyPosition[i].columnCoordinate = 255;
  }
}

// TO BE COMPLETED
void defineMockSnakesOnePositions() {
  mockPlayers[1].bodyPosition[0].lineCoordinate = 9;
  mockPlayers[1].bodyPosition[0].columnCoordinate = 29;
  
  mockPlayers[1].bodyPosition[1].lineCoordinate = 9;
  mockPlayers[1].bodyPosition[1].columnCoordinate = 30;
  
  mockPlayers[1].bodyPosition[2].lineCoordinate = 9;
  mockPlayers[1].bodyPosition[2].columnCoordinate = 31;
  
  mockPlayers[1].bodyPosition[3].lineCoordinate = 10;
  mockPlayers[1].bodyPosition[3].columnCoordinate = 31;
  
  mockPlayers[1].bodyPosition[4].lineCoordinate = 11;
  mockPlayers[1].bodyPosition[4].columnCoordinate = 31;
  
  mockPlayers[1].bodyPosition[5].lineCoordinate = 12;
  mockPlayers[1].bodyPosition[5].columnCoordinate = 31;
  
  mockPlayers[1].bodyPosition[6].lineCoordinate = 13;
  mockPlayers[1].bodyPosition[6].columnCoordinate = 31;
  
  mockPlayers[1].bodyPosition[7].lineCoordinate = 14;
  mockPlayers[1].bodyPosition[7].columnCoordinate = 31;
  
  mockPlayers[1].bodyPosition[8].lineCoordinate = 15;
  mockPlayers[1].bodyPosition[8].columnCoordinate = 31;
  
  mockPlayers[1].bodyPosition[9].lineCoordinate = 16;
  mockPlayers[1].bodyPosition[9].columnCoordinate = 31;
  
  mockPlayers[1].bodyPosition[10].lineCoordinate = 17;
  mockPlayers[1].bodyPosition[10].columnCoordinate = 31;
  
  mockPlayers[1].bodyPosition[11].lineCoordinate = 17;
  mockPlayers[1].bodyPosition[11].columnCoordinate = 30;
  
  mockPlayers[1].bodyPosition[12].lineCoordinate = 18;
  mockPlayers[1].bodyPosition[12].columnCoordinate = 30;
  
  mockPlayers[1].bodyPosition[13].lineCoordinate = 19;
  mockPlayers[1].bodyPosition[13].columnCoordinate = 30;
  
  mockPlayers[1].bodyPosition[14].lineCoordinate = 20;
  mockPlayers[1].bodyPosition[14].columnCoordinate = 30;
  
  mockPlayers[1].bodyPosition[15].lineCoordinate = 21;
  mockPlayers[1].bodyPosition[15].columnCoordinate = 30;
  
  mockPlayers[1].bodyPosition[16].lineCoordinate = 22;
  mockPlayers[1].bodyPosition[16].columnCoordinate = 30;

 for(byte i = 17; i<maxSnakeSize; i++) {
    mockPlayers[1].bodyPosition[i].lineCoordinate = 255;
    mockPlayers[1].bodyPosition[i].columnCoordinate = 255;
  }
}

void defineMockSnakesTwoPositions() {
  mockPlayers[2].bodyPosition[0].lineCoordinate = 4;
  mockPlayers[2].bodyPosition[0].columnCoordinate = 9;
  
  mockPlayers[2].bodyPosition[1].lineCoordinate = 4;
  mockPlayers[2].bodyPosition[1].columnCoordinate = 10;
  
  mockPlayers[2].bodyPosition[2].lineCoordinate = 4;
  mockPlayers[2].bodyPosition[2].columnCoordinate = 11;
  
  mockPlayers[2].bodyPosition[3].lineCoordinate = 4;
  mockPlayers[2].bodyPosition[3].columnCoordinate = 12;
  
  mockPlayers[2].bodyPosition[4].lineCoordinate = 4;
  mockPlayers[2].bodyPosition[4].columnCoordinate = 13;
  
  mockPlayers[2].bodyPosition[5].lineCoordinate = 4;
  mockPlayers[2].bodyPosition[5].columnCoordinate = 14;
  
  mockPlayers[2].bodyPosition[6].lineCoordinate = 4;
  mockPlayers[2].bodyPosition[6].columnCoordinate = 15;
  
  mockPlayers[2].bodyPosition[7].lineCoordinate = 4;
  mockPlayers[2].bodyPosition[7].columnCoordinate = 16;
  
  mockPlayers[2].bodyPosition[8].lineCoordinate = 5;
  mockPlayers[2].bodyPosition[8].columnCoordinate = 16;
  
  mockPlayers[2].bodyPosition[9].lineCoordinate = 6;
  mockPlayers[2].bodyPosition[9].columnCoordinate = 16;
  
  mockPlayers[2].bodyPosition[10].lineCoordinate = 7;
  mockPlayers[2].bodyPosition[10].columnCoordinate = 16;
  
  mockPlayers[2].bodyPosition[11].lineCoordinate = 8;
  mockPlayers[2].bodyPosition[11].columnCoordinate = 16;
  
  mockPlayers[2].bodyPosition[12].lineCoordinate = 8;
  mockPlayers[2].bodyPosition[12].columnCoordinate = 17;
  
  mockPlayers[2].bodyPosition[13].lineCoordinate = 8;
  mockPlayers[2].bodyPosition[13].columnCoordinate = 18;
  
  mockPlayers[2].bodyPosition[14].lineCoordinate = 8;
  mockPlayers[2].bodyPosition[14].columnCoordinate = 19;
  
  mockPlayers[2].bodyPosition[15].lineCoordinate = 8;
  mockPlayers[2].bodyPosition[15].columnCoordinate = 20;
  
  mockPlayers[2].bodyPosition[16].lineCoordinate = 8;
  mockPlayers[2].bodyPosition[16].columnCoordinate = 21;
  
  mockPlayers[2].bodyPosition[17].lineCoordinate = 8;
  mockPlayers[2].bodyPosition[17].columnCoordinate = 22;
  
  mockPlayers[2].bodyPosition[18].lineCoordinate = 8;
  mockPlayers[2].bodyPosition[18].columnCoordinate = 23;
  
  mockPlayers[2].bodyPosition[19].lineCoordinate = 7;
  mockPlayers[2].bodyPosition[19].columnCoordinate = 23;
  
  mockPlayers[2].bodyPosition[20].lineCoordinate = 6;
  mockPlayers[2].bodyPosition[20].columnCoordinate = 23;
  
  mockPlayers[2].bodyPosition[21].lineCoordinate = 5;
  mockPlayers[2].bodyPosition[21].columnCoordinate = 23;
  
  mockPlayers[2].bodyPosition[22].lineCoordinate = 5;
  mockPlayers[2].bodyPosition[22].columnCoordinate = 23;
  
  mockPlayers[2].bodyPosition[23].lineCoordinate = 5;
  mockPlayers[2].bodyPosition[23].columnCoordinate = 24;
  
  mockPlayers[2].bodyPosition[24].lineCoordinate = 5;
  mockPlayers[2].bodyPosition[24].columnCoordinate = 25;
  
  mockPlayers[2].bodyPosition[25].lineCoordinate = 5;
  mockPlayers[2].bodyPosition[25].columnCoordinate = 26;
  
  for(byte i = 26; i<maxSnakeSize; i++) {
    mockPlayers[2].bodyPosition[i].lineCoordinate = 255;
    mockPlayers[2].bodyPosition[i].columnCoordinate = 255;
  }
}

void defineMockSnakesThreePositions() {
  mockPlayers[3].bodyPosition[0].lineCoordinate = 21;
  mockPlayers[3].bodyPosition[0].columnCoordinate = 4;
  
  mockPlayers[3].bodyPosition[1].lineCoordinate = 21;
  mockPlayers[3].bodyPosition[1].columnCoordinate = 3;
  
  mockPlayers[3].bodyPosition[2].lineCoordinate = 21;
  mockPlayers[3].bodyPosition[2].columnCoordinate = 2;
  
  mockPlayers[3].bodyPosition[3].lineCoordinate = 20;
  mockPlayers[3].bodyPosition[3].columnCoordinate = 2;
  
  mockPlayers[3].bodyPosition[4].lineCoordinate = 19;
  mockPlayers[3].bodyPosition[4].columnCoordinate = 2;
  
  mockPlayers[3].bodyPosition[5].lineCoordinate = 18;
  mockPlayers[3].bodyPosition[5].columnCoordinate = 2;
  
  mockPlayers[3].bodyPosition[6].lineCoordinate = 17;
  mockPlayers[3].bodyPosition[6].columnCoordinate = 2;
  
  mockPlayers[3].bodyPosition[7].lineCoordinate = 16;
  mockPlayers[3].bodyPosition[7].columnCoordinate = 2;
  
  mockPlayers[3].bodyPosition[8].lineCoordinate = 15;
  mockPlayers[3].bodyPosition[8].columnCoordinate = 2;
  
  mockPlayers[3].bodyPosition[9].lineCoordinate = 14;
  mockPlayers[3].bodyPosition[9].columnCoordinate = 2;
  
  mockPlayers[3].bodyPosition[10].lineCoordinate = 13;
  mockPlayers[3].bodyPosition[10].columnCoordinate = 2;
  
  mockPlayers[3].bodyPosition[11].lineCoordinate = 13;
  mockPlayers[3].bodyPosition[11].columnCoordinate = 3;
  
  mockPlayers[3].bodyPosition[12].lineCoordinate = 13;
  mockPlayers[3].bodyPosition[12].columnCoordinate = 4;
  
  mockPlayers[3].bodyPosition[13].lineCoordinate = 12;
  mockPlayers[3].bodyPosition[13].columnCoordinate = 4;
  
  mockPlayers[3].bodyPosition[14].lineCoordinate = 11;
  mockPlayers[3].bodyPosition[14].columnCoordinate = 4;
  
  mockPlayers[3].bodyPosition[15].lineCoordinate = 10;
  mockPlayers[3].bodyPosition[15].columnCoordinate = 4;
  
  mockPlayers[3].bodyPosition[16].lineCoordinate = 9;
  mockPlayers[3].bodyPosition[16].columnCoordinate = 4;
  
  mockPlayers[3].bodyPosition[17].lineCoordinate = 8;
  mockPlayers[3].bodyPosition[17].columnCoordinate = 4;
  
  mockPlayers[3].bodyPosition[18].lineCoordinate = 7;
  mockPlayers[3].bodyPosition[18].columnCoordinate = 4;
  
  mockPlayers[3].bodyPosition[19].lineCoordinate = 7;
  mockPlayers[3].bodyPosition[19].columnCoordinate = 3;
  
  for(byte i = 20; i<maxSnakeSize; i++) {
    mockPlayers[3].bodyPosition[i].lineCoordinate = 255;
    mockPlayers[3].bodyPosition[i].columnCoordinate = 255;
  }
}
