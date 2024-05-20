#include "Mario.h"

    Mario::Mario(){
        coins = 0;
        PL = 0;
        defeatCounter = 0;
        srand(time(0));
    }
    
    Mario::~Mario(){}

    int Mario::movement(){
        int direc;
        direc = 1+ (rand() % 4);
        return(direc);
    }

void Mario::setLives(int V){
    lives = V;
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
    if(lives <= 0){
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

string Mario::result(){

    returnOutcome = " Mario is at power level " + to_string(PL) + outcome + " Mario has " + to_string(lives) + " lives left." + " Mario has " + to_string(coins) + " coins.";

  return returnOutcome;
}




    int Mario::interact(char item) {
        
        /*result: 1-means the tile can be cleared 2-means mario lost and stays at tile until beating enemy 3-found a warp pipe 4-beat a boss
        and advance to next level */
        int result;

      if(item == 'x'){
          outcome = " The position is empty.";
          result = 1;
      } else

        /*checks if item is a coin*/
        if(item == 'c'){
              outcome = " Mario collected a coin.";
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
          outcome = " Mario ate a mushroom." ;
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
              outcome = " Mario fought a Goomba and won.";
                defeatedEnemy();
                result = 1;
            } else {
              outcome = " Mario fought a Goomba and lost.";
                takeDamage();
                result = checkLives();
            }
        }

        /*check if the item is a koopa troopa*/
        if(item == 'k'){
            /*call the regular enemy function*/
            if(objects.koopa() == true){
              outcome = " Mario fought a Koopa and won." ;
                defeatedEnemy();
                result = 1;
            } else {
              outcome = " Mario fought a Koopa and lost." ;
                takeDamage();
                result = checkLives();
            }
        }

        /*check if the item is the level boss*/
        if(item == 'b'){
            /*call the regular enemy function*/
            if(objects.boss() == true){
              outcome = " Mario encountered a boss and won.";
                defeatedEnemy();
                result = 4;
            } else {
              outcome = " Mario encountered a boss and lost.";
                /*check lives has to be called twice because he lost 2 PL*/
                takeDamage();
                if (checkLives() == 5){     //condition if Mario dies to boss with 1 life. Instead of -1                                                     lives, setting it to 0 
                    result = checkLives(); 
                }
                else {
                    takeDamage();
                    result = checkLives();
                }
            }
        }

        if(item == 'w'){
          outcome = " Mario found a warp pipe.";
            result = 4;
        }

        // cout << "Lives: " << lives << " PL: " << PL << " defeat counter: " << defeatCounter << " result: " << result << "coins: " << coins << endl;
        return result;

    }