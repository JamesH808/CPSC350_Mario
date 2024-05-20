#include "Mario.h"

int main(int argc, char **argv){

    int input;
    int i=0;
    char itemInput;
    cout << "Mario's lives? " << endl;
    cin >> input;
    Mario newMario(input);

    while(i < 3){
        cout << "item? " << endl;
        cin >> itemInput;
        newMario.interact(itemInput);
        i++;
    }






}