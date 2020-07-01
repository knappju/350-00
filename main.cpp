#include <iostream>
#include <stdlib.h>
#include "simonsays.h"

using namespace std;



int main (){

    SimonSays game1{};
    int guess;

    do{
        scanf("%d", &guess);
    }while(!(game1.makeGuess(guess)));
    return 0;

}

