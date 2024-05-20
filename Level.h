#include "Mario.h"
#ifndef LEVEL_H
#define LEVEL_H


class Level{
    
  public:
    Level();
    ~Level();
        

    char** createLevel(int N);
    void setWeights(int array[]);
    void populate();
    void traverse();

    char ** twoD;
    int row;
    int col;
    char things[7] = {'c', 'x', 'g', 'k', 'm', 'w', 'b'};
    int chance;

    int nothing = 10;
    int mushroom = 10;
    int coin = 30;
    int goomba = 25;
    int koopa = 25;




};

#endif
