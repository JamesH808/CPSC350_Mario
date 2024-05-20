#include "Mario.h"

    Mario::Mario(int V){
        coins = 0;
        lives = V;
        PL = 0;
        defeatCounter = 0;
    }
    
    Mario::~Mario(){}

    int Mario::movement(){
        srand(time(0));
        int direc;
        direc = 1+ (rand() % 4);
        cout << "testing values for random movement: " << direc << endl;
        return(direc);
    }


void Mario::takeDamage(){
    /*checks if mario has PL lower than 0 to start taking away lives, but his PL must stay at 0*/
    /*if he loses a life his defeat counter has to reset*/
    PL--;
    if(PL < 0){
        lives--;
        PL = 0;
        defeatCounter = 0;
    }
        
}

int Mario::checkLives(){
    if(lives == 0){
        return 5;
    } else {
        return 2;
    }
}

void Mario::defeatedEnemy(){
    /*checks if mario has beat 7 enemies, if he has he gains a life and counter resets*/
    if(defeatCounter == 7){
        lives++;
        defeatCounter = 0;
    }
    defeatCounter++; 
}




    int Mario::interact(char item) {
        
        /*result: 1-means the tile can be cleared 2-means mario lost and stays at tile until beating enemy 3-found a warp pipe 4-beat a boss
        and advance to next level */
        int result;

        /*checks if item is a coin*/
        if(item == 'c'){
            cout << "Mario collected a coin" << endl;
            coins++;
            if(coins == 20){
                /*when there's 20 coins, mario gains a power level up to level 2*/
                coins = 0;
                if(PL != 2){
                    PL++;
                }
            }
            result = 1;
        } else

        /*check if the item is a mushroom*/
        if(item == 'm'){
            cout << "Mario ate a mushroom" << endl;
            /*give mario another power level, unless he is maxed at 2*/
            if(PL != 2){
                PL++;
            }
            result = 1;
        } else

        /*check if the item is a goomba*/
        if(item == 'g'){
            /*call the regular enemy function*/
            if(objects.goomba() == true){
                cout << "Mario fought a Goomba and won" << endl;
                defeatedEnemy();
                result = 1;
            } else {
                cout << "Mario fought a Goomba and lost" << endl;
                takeDamage();
                result = checkLives();
            }
        }

        /*check if the item is a koopa troopa*/
        if(item == 'k'){
            /*call the regular enemy function*/
            if(objects.koopa() == true){
                cout << "Mario fought a Koopa and won" << endl;
                defeatedEnemy();
                result = 1;
            } else {
                cout << "Mario fought a Koopa and lost" << endl;
                takeDamage();
                result = checkLives();
            }
        }

        /*check if the item is the level boss*/
        if(item == 'b'){
            /*call the regular enemy function*/
            if(objects.boss() == true){
                cout << "Mario fought the level boss and won" << endl;
                defeatedEnemy();
                result = 4;
            } else {
                cout << "Mario fought the level boss and lost" << endl;
                /*check lives has to be called twice because he lost 2 PL*/
                takeDamage();
                takeDamage();
                result = checkLives();
            }
        }

        if(item == 'w'){
            result = 4;
        }

        cout << "Lives: " << lives << " PL: " << PL << " defeat counter: " << defeatCounter << " result: " << result << endl;
        return result;

    }