#ifndef WORLD_H
#define WORLD_H

#include "Level.h"

class World{
  public:
  World();
  ~World();

  void makeWorld(int array[]);
  void printWorld();
  void play();
  void inBounds(int L, int row, int col);
  void moveMario(int d);
void printLevel(int i);

  int numLevels;
  char *** world;
  int N;
int i;
  int marioX;
  int marioY;
int lives;
  int marioResult;
int direction;
string Direction; // for printing up, down, left, right in output file 

  private:
  Level level;
  Mario mario;
  

};

#endif