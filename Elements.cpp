#include "elements.h"

Elements::Elements(){
}

Elements::~Elements(){}

int Elements::randomChance(){
    srand(time(0));
    chance = 1 + (rand() % 100);
}


bool Elements::goomba(){

    /*for the goomba*/
    randomChance();

        
    cout << "chance: " << chance << endl;

    /*if he beats the goomba, clear the tile and return that he WON*/
    if(chance <= 80){
        outcome = true;
    } else {
        outcome = false;
    }

    return outcome;
} 
        
bool Elements::koopa(){
    /*for the koopa*/
    randomChance();
    if(chance <= 65){

        outcome = true;

    } else {

        outcome = false;
    }

        return outcome;
}

bool Elements::boss(){
    randomChance();
    if(chance <= 5){

        outcome = true;

    } else {
        outcome = false;
    }

    return outcome;
}