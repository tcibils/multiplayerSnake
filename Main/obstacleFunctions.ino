// This function is to be called at the start of a game, to define which obstacles will be used for that game.
void initializeGameObstacles() {
  // First we clear any existing obstacles
  clearObstacles();

  // Then we use a random number to define what obstacles we'll deal with
  byte randomNumber = random(0,100);

  // In 30% of the cases
  if(randomNumber < 30) {
    // We do not put any obstacles, simply.
  }

  // In 30% of the cases
  if(randomNumber >= 30 && randomNumber < 60)  {
    // We only put walls
    defineObstacleWalls();
  }

  // Other cases yet TBD
  
}

// Put four walls around the map, so that players cannot pass through
void defineObstacleWalls() {
  // Top wall
  defineObstacle(0,0,32,1,White);

  // Left wall
  defineObstacle(0,0,1,32,White);

  // Bottom wall
  defineObstacle(31,0,32,1,White);

  // Right wall
  defineObstacle(0,31,1,32,White);
}


// Allows to fill the Obstacles matrix with whatever obstacles we want
void defineObstacle(const byte startingLine, const byte startingColumn, const byte horizontalLength, const byte verticalLength, const byte colourChoice) {
  
  for(byte horizontalIterator = 0; horizontalIterator < horizontalLength; horizontalIterator++) {
    for(byte verticalIterator = 0; verticalIterator < verticalLength; verticalIterator++) {
      Obstacles[startingLine + horizontalIterator][startingColumn + verticalIterator] = colourChoice;
    }
  }
}

// Fully clears the obstacles
void clearObstacles() {
  for(byte horizontalIterator = 0; horizontalIterator < totalDisplayNumberOfRows; horizontalIterator++) {
    for(byte verticalIterator = 0; verticalIterator < totalDisplayNumberOfColumns; verticalIterator++) {
      Obstacles[horizontalIterator][verticalIterator] = Black;
    }
  }
}

// Takes all the obstacle matrix, which contains them all, and fills the LED Matrix with them so that they get displayed
void displayObstacles() {
  for(byte horizontalIterator = 0; horizontalIterator < totalDisplayNumberOfRows; horizontalIterator++) {
    for(byte verticalIterator = 0; verticalIterator < totalDisplayNumberOfColumns; verticalIterator++) {
      LEDMatrix[horizontalIterator][verticalIterator] = Obstacles[horizontalIterator][verticalIterator];
    }
  }  
}
