# multiplayerSnake
Snake, but as a battle royal with up to 4 players. 

This is a 2 to 4 players game. The goal of each player is simply to be the last remaining player on the board. To do so, other players' snake heads must hit something and die, as in the usual snake game. 

There are 3 "game phases" :
- A starting screen, which displays "Snake" in Glooming green, and 4 "mock-snakes" around it, to let player chose to enter the game and chose their colours. By pressing start, the game launches. 
- The actual game, where each player makes his snake move around (direction input is adapted depending on the table side the player is), catch normal apples to get bigger, and catch purple apples to get faster (each player has an independent speed). It's possible to go from one side of the board to the other. 
- And finally, once there's only one remaining active player, a final game state to show who won, and display fireworks. 

The starting and final screen are fixed sized, and adapted to my 32x32 led matrix, but the central game is generic enough to be re-used on other sized led matrices. 
