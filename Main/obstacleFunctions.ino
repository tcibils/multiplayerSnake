// This function is to be called at the start of a game, to define which obstacles will be used for that game.
void initializeGameObstacles() {
  // First we clear any existing obstacles
  clearObstacles();

  // Then we use a random number to define what obstacles we'll deal with
  byte randomNumber = random(0,100);


  // In 25% of the cases
  if(randomNumber < 25)  {
    // We only put walls
    defineObstacleWalls();
  }

  // In 20% of the cases
  else if(randomNumber >= 25 && randomNumber < 50) {
    // We put walls on the corners only, so players will have gates to pass through
    defineObstacleCorners();
  }

  // Below is the fun part, should be around 30%, so up 75

  else if(randomNumber >= 55 && randomNumber < 65 ) {
    defineObstacleCentralBars();
  }
/*
  else if(randomNumber >= 60 && randomNumber < 65) {
    // That won't work, because of the player starting positions
    // defineObstacleSmallerMap();
  }
  */

  else if(randomNumber >= 65 && randomNumber < 70) {
    defineObstacleBigPlus();
  }

  else if(randomNumber >= 70 && randomNumber < 75) {
    defineObstacleCentralSquare();
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


void defineObstacleCentralBars() {
  defineObstacle(9,6,1,16,White);
  // Initial apples are between those walls
  defineObstacle(9,10,1,16,White);  

  // Big central corridor
  
  defineObstacle(9,21,1,16,White);
  // Initial apples are between those walls
  defineObstacle(9,25,1,16,White);
}

/*
// That won't work, because of the player starting positions
void defineObstacleSmallerMap() {
  // Top wall
  defineObstacle(0,0,32,5,White);

  // Left wall
  defineObstacle(0,0,5,32,White);

  // Bottom wall
  defineObstacle(31,0,32,5,White);

  // Right wall
  defineObstacle(0,31,5,32,White);
  
}
*/

void defineObstacleBigPlus() {
  defineObstacle(15,0,32,1,White);
  defineObstacle(0,15,1,32,White);
}

void defineObstacleCentralSquare() {
  defineObstacle(12,12,8,8,White);
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

void defineObstacleCorners() {
   // Top wall
  defineObstacle(0,0,10,1,White);
  defineObstacle(0,21,10,1,White);

  // Left wall
  defineObstacle(0,0,1,10,White);
  defineObstacle(21,0,1,10,White);

  // Bottom wall
  defineObstacle(31,0,10,1,White);
  defineObstacle(31,21,10,1,White);

  // Right wall
  defineObstacle(0,31,1,10,White);
  defineObstacle(21,31,1,10,White);
}



// ----------------------------------------------------------------------------------------------------
// -------------------------------------   GENERIC OBSTACLE FUNCTIONS  --------------------------------
// ----------------------------------------------------------------------------------------------------

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
