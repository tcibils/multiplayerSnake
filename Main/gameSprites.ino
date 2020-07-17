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
