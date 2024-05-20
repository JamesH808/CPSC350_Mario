#include "Level.h"

Level::Level() {
  srand(time(0)); // construcotr
}

Level::~Level() { 
  for (int f = 1; f < row; ++f) {
    delete[] twoD[f];
       
  }
    delete[] twoD;
  
  
  } // destructor

void Level::setWeights(int array[]){
  coin = array[3];
  nothing = array[4];
  goomba = array[5];
  koopa = array[6];
  mushroom = array[7];

}

char **Level::createLevel(int N) {
  row = N;
  col = N;
  // Allocate memory for the rows
  twoD = new char *[row];

  // Allocate memory for each column in every row
  for (int i = 0; i < row; ++i) {
    twoD[i] = new char[col];
  }
  // Populate the grid
  populate();

  return twoD; // Return the pointer to the 2D array
}

void Level::populate() {
  /*the following will iterate through the 2d array and populate it with a
   * weighted percentage to choose each character*/
  // srand(time(0));

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      chance = 1 + (rand() % 100);
      if (chance > 0 && chance <= coin) {
        twoD[i][j] = things[0];
      } else if (chance > coin && chance <= (nothing + coin)) {
        twoD[i][j] = things[1];
      } else if (chance > (nothing + coin) &&
                 chance <= (nothing + goomba + coin)) {
        twoD[i][j] = things[2];
      } else if (chance > (nothing + goomba + coin) &&
                 chance <= (nothing + koopa + coin + goomba)) {
        twoD[i][j] = things[3];
      } else if (chance > (nothing + koopa + coin + goomba) &&
                 chance <= (nothing + mushroom + coin + goomba + koopa)) {
        twoD[i][j] = things[4];
      }
    }
  }

  /*pick a random number between 0 and the number of rows and columns and place
   * a warp pipe there and boss*/
  twoD[rand() % row][rand() % col] = things[5];
  twoD[rand() % row][rand() % col] = things[6];
}

