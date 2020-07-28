// This function is to be called at the start of a game, to define which obstacles will be used for that game.
void initializeGameObstacles() {
  // First we clear any existing obstacles
  clearObstacles();

  // Then we use a random number to define what obstacles we'll deal with
  byte randomNumber = random(0,100);

  // In 25% of the cases
  if(randomNumber < 25)  {
    // We only put walls
    defineObstacleWalls(obstacleColour);
  }

  // In 20% of the cases
  else if(randomNumber >= 25 && randomNumber < 50) {
    // We put walls on the corners only, so players will have gates to pass through
    defineObstacleCorners(obstacleColour);
  }

  // Below is the fun part, should be around 30%, so up 75

  else if(randomNumber >= 50 && randomNumber < 52 ) {
    defineObstacleCentralBars(obstacleColour);
  }
  
/*
  else if(randomNumber >= 60 && randomNumber < 65) {
    // That won't work, because of the player starting positions
    // defineObstacleSmallerMap();
  }
  */

  else if(randomNumber >= 55 && randomNumber < 60) {
    defineObstacleBigPlus(obstacleColour);
  }

  else if(randomNumber >= 60 && randomNumber < 65) {
    defineObstacleCentralSquare(obstacleColour);
  }

    // All remaining cases (should be around 25%)
  else {
    // We do nothing and do not put any wall up
  }

}




// ----------------------------------------------------------------------------------------------------
// -----------------------   OBSTACLE DEFINITION FUNCTIONS   ------------------------------------------
// ----------------------------------------------------------------------------------------------------

/*
Angles ouverts -> 2%
Barres au milieu -> 10 et 10 %
Gros + au milieu pour découper en 4 cadrans... Qui se combine avec les différentes possibilités de murs =)  -> 2% et 2%
Smaller map by walling out a lot -> 2%
un seul gros bloc -> 2%
*/


void defineObstacleCentralBars(byte displayColour) {
  defineObstacle(9,6,1,16,displayColour);
  // Initial apples are between those walls
  defineObstacle(9,12,1,16,displayColour);  

  // Big central corridor
  
  defineObstacle(9,19,1,16,displayColour);
  // Initial apples are between those walls
  defineObstacle(9,25,1,16,displayColour);
}

/*
// That won't work, because of the player starting positions
void defineObstacleSmallerMap(byte displayColour) {
  // Top wall
  defineObstacle(0,0,32,5,displayColour);

  // Left wall
  defineObstacle(0,0,5,32,displayColour);

  // Bottom wall
  defineObstacle(31,0,32,5,displayColour);

  // Right wall
  defineObstacle(0,31,5,32,displayColour);
  
}
*/

void defineObstacleBigPlus(byte displayColour) {
  defineObstacle(15,0,32,1,displayColour);
  defineObstacle(0,15,1,32,displayColour);
}

void defineObstacleCentralSquare(byte displayColour) {
  defineObstacle(12,12,8,8,displayColour);
}

// Put four walls around the map, so that players cannot pass through
void defineObstacleWalls(byte displayColour) {
  // Top wall
  defineObstacle(0,0,32,1,displayColour);

  // Left wall
  defineObstacle(0,0,1,32,displayColour);

  // Bottom wall
  defineObstacle(31,0,32,1,displayColour);

  // Right wall
  defineObstacle(0,31,1,32,displayColour);
  
}

void defineObstacleCorners(byte displayColour) {
   // Top wall
  defineObstacle(0,0,10,1,displayColour);
  defineObstacle(0,21,10,1,displayColour);

  // Left wall
  defineObstacle(0,0,1,10,displayColour);
  defineObstacle(21,0,1,10,displayColour);

  // Bottom wall
  defineObstacle(31,0,10,1,displayColour);
  defineObstacle(31,21,10,1,displayColour);

  // Right wall
  defineObstacle(0,31,1,10,displayColour);
  defineObstacle(21,31,1,10,displayColour);
}



// ----------------------------------------------------------------------------------------------------
// -------------------------------------   GENERIC OBSTACLE FUNCTIONS  --------------------------------
// ----------------------------------------------------------------------------------------------------

// Allows to fill the Obstacles matrix with whatever obstacles we want
void defineObstacle(const byte startingLine, const byte startingColumn, const byte horizontalLength, const byte verticalLength, const byte colourChoice) {
  
  for(byte horizontalIterator = 0; horizontalIterator < horizontalLength; horizontalIterator++) {
    for(byte verticalIterator = 0; verticalIterator < verticalLength; verticalIterator++) {
      Obstacles[startingLine + verticalIterator][startingColumn + horizontalIterator] = colourChoice;
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
  // We iterate on all the matrix size
  for(byte horizontalIterator = 0; horizontalIterator < totalDisplayNumberOfRows; horizontalIterator++) {
    for(byte verticalIterator = 0; verticalIterator < totalDisplayNumberOfColumns; verticalIterator++) {
      // If there is nothing on a spot (no player, no apple) (we want to avoid to put a LED to black if we previously already printed somthing there, so we only override potential existing black spaces)
      if(LEDMatrix[horizontalIterator][verticalIterator] == 0) {
        // Then we display the potential obstacle
        LEDMatrix[horizontalIterator][verticalIterator] = Obstacles[horizontalIterator][verticalIterator];
      }
    }
  }  
}
