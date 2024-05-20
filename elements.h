#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <iostream>
#include <cstdlib>
using namespace std;

class Elements{
    
    public:
        Elements();
        ~Elements();

        int randomChance();
        bool goomba();
        bool koopa();
        bool boss();
        bool outcome;
        int chance;


    



};

#endif