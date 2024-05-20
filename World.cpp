#include "World.h"


World::World(){
  srand(time(0));
  i=0;
  
}

World::~World(){
  for (int i = 0; i < numLevels; ++i) { // For each level
    for (int j = 0; j < N; ++j) { // For each row in the level
      delete[] world[i][j]; // Delete each row
    }
    delete[] world[i]; // Delete the array of rows (the level)
  }
  delete[] world; // Delete the array of pointers to levels
  
}

void World::makeWorld(int array[]){

  numLevels = array[0];
  N = array[1];
  lives = array[2];
  level.setWeights(array);
  
  mario.setLives(lives);

  world = new char**[numLevels];

  // for (int i = 0; i < numLevels; ++i) {
  //     world[i] = new char*[numLevels];
  //     for (int j = 0; j < N; ++j) {
  //         world[i][j] = new char[N];
  //     }

  // }
  
  for (int i = 0; i < numLevels; ++i) {
    world[i] = level.createLevel(N);
  }

  
}

 void World::printWorld(){
   for (int i = 0; i < numLevels; ++i){
         for (int j = 0; j < N; ++j) {
             for (int k = 0; k < N; ++k) {
                 // Print the values
                 cout << world[i][j][k] << " ";
             }
             cout << endl;
         }
         //cout << endl;
        cout << "==========" << endl;
     }
 }

void World::printLevel(int i){
         for (int j = 0; j < N; ++j) {
             for (int k = 0; k < N; ++k) {
                 // Print the values
                 cout << world[i][j][k] << " ";
             }
             cout << endl;
         }
         //cout << endl;
        cout << "==========" << endl;
 }

void World::inBounds(int L, int row, int col){

  if(row < 0){
    marioX = row + N;
  } else if(row >= N){
    marioX = row - N;
  } else if(col < 0){
    marioY = col + N;
  } else if(col >= N){
    marioY = col - N;
  } else {

    marioX = row;
    marioY = col;

  }

}

void World::moveMario(int direc){

  if(direction == 1){
    /*up*/
    world[i][marioX][marioY] = 'x';
      inBounds(i, marioX - 1, marioY);
    Direction = "up";
      
  } else if (direction == 2){
    /*right*/
    world[i][marioX][marioY] = 'x';
      inBounds(i, marioX , marioY + 1);
      Direction = "right";
  } else if (direction == 3){
    /*down*/
    world[i][marioX][marioY] = 'x';
      inBounds(i, marioX + 1, marioY);
      Direction = "down";
  } else if (direction == 4){
    /*left*/
    world[i][marioX][marioY] = 'x';
      inBounds(i, marioX, marioY -1);
      Direction = "left";
  }
  
}

/*TODO: put all conditionals in here later */
void World::play(){
  
  char tile;
  marioX = rand() % N;
  marioY = rand() % N;



  printWorld();

  cout << "Mario is starting in position:" << endl;
  cout << "(" << marioX << "," << marioY << ")" << endl;
  cout << "==========" << endl;

  tile = world[i][marioX][marioY];
  world[i][marioX][marioY] = 'H';
   printLevel(i);
  marioResult = mario.interact(tile);


  

  while(mario.checkLives() != 5){
    
     
    
     // cout << "Level: " << i << ". " << "Mario is at position: " << "(" << marioX << "," << marioY << "). "   << mario.result() << endl;

     // marioResult = mario.interact(tile);
      
     
    

    if(marioResult == 1){
      /*mario can move to another tile*/
      direction = mario.movement();
      moveMario(direction);
      cout << "Level: " << i << ". " << "Mario is at position: " << "(" << marioX << "," << marioY << "). "   << mario.result() << endl;
      cout << "Mario will move: " << Direction << endl;
      cout << "==========" << endl;
      tile = world[i][marioX][marioY];
      world[i][marioX][marioY] = 'H';
      printLevel(i);
      marioResult = mario.interact(tile);
      
    } else if(marioResult == 2){
      /*Mario has to continue at the position */

      /*TODO: cout that he will stay put as his direction */
      // direction = 5;
      cout << "Level: " << i << ". " << "Mario is at position: " << "(" << marioX << "," << marioY << "). "   << mario.result() << endl;
      cout << "Mario will stay put." << endl;
      cout << "==========" << endl;
      printLevel(i);
      marioResult = mario.interact(tile);
      continue;
      
    } else if(marioResult == 4){
      /*Mario has to go to the next level*/
      /*Set new starting position for the next level */
      cout << "Level: " << i << ". " << "Mario is at position: " << "(" << marioX << "," << marioY << "). "   << mario.result() << endl;
      
      ++i;
      if(i >= numLevels){
        break;
      }
      marioX = rand() % N;
      marioY = rand() % N;
      cout << "==========" << endl;
      tile = world[i][marioX][marioY];
      world[i][marioX][marioY] = 'H';
      printLevel(i);
      marioResult = mario.interact(tile);
      
      
    } else if(marioResult == 5){
      cout << "Level: " << i << ". " << "Mario is at position: " << "(" << marioX << "," << marioY << "). "   << mario.result() << endl;
      break;
    } 

  }

  if(mario.checkLives() == 5){
  cout << "WE LOST THE GAME! :(" << endl;
  } else {
    cout << "WE BEAT THE GAME! :)" << endl;
  }

}