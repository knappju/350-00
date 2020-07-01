#ifndef SIMONSAYS_H
#define SIMONSAYS_H

#include <iostream>
#include <stdlib.h>
#include <time.h>


#define SIMONSAYSSIZE (100U)

using namespace std;

class SimonSays{

    private:
        int whatSimonSaid[SIMONSAYSSIZE];
        int levelCounter, guessPosition;

        void initGame();
        void determineWhatSimonWillSay();
        void printChallenge(int printToIndex);

    public:
        SimonSays(){
            initGame();
            printChallenge(levelCounter);
        };
        
        void printFullSimonArray(){printChallenge(SIMONSAYSSIZE - 1);};
        int makeGuess(int guess);


};


void SimonSays::initGame(){
    levelCounter = 0;
    guessPosition = 0;
    determineWhatSimonWillSay();
}

void SimonSays::determineWhatSimonWillSay(){
    srand(time (NULL));
    for(int i = 0; i < SIMONSAYSSIZE; i++){
        whatSimonSaid[i] = rand() % 4 + 1;
    }
}

void SimonSays::printChallenge(int printToIndex){
    int a = 0;
    while(a <= printToIndex){
        cout << a << ": " << whatSimonSaid[a] << endl;
        a++;
    }
        
}

int SimonSays::makeGuess(int guess){
    int status = 0;
    if(guess == whatSimonSaid[guessPosition]){ 
        if(guessPosition >= levelCounter){
            cout << "Next Level" << endl;
            guessPosition = 0;
            levelCounter++;
            printChallenge(levelCounter);
        }
        else{
            cout << "good guess" << endl;
            guessPosition++;
        }
    }
    else{
        guessPosition = 0;
        levelCounter = 0;
        cout << "you lose;" << endl;
        status = 1;
    }
    return status;
}


#endif /* SIMONSAYS.H */
