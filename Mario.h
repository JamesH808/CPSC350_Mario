#include "elements.h"
#ifndef MARIO_H
#define MARIO_H

class Mario : public Elements{
    
    public:
        Mario();
        ~Mario();

        int movement();
        int interact(char item);
        void defeatedEnemy();
        void takeDamage();
        int checkLives();
        void setLives(int V);
        string result();

        int defeatCounter;
        int coins;
        int lives;
        int PL;
        string outcome;
        string returnOutcome;
    
    private:
        Elements objects;




};

#endif