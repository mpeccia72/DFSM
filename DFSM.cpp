
#include "DFSM.h"

// constructor
DFSM::DFSM() {

}

// initializes array
void DFSM::buildMachine() {

    dfsmChart = new int*[stateCount];
    
    for(int i = 0; i < stateCount; i++) {
        dfsmChart[i] = new int[characters.size()];
    }

}

// determines if the string is accepted by machine
bool DFSM::isAccepted(string input) {

    // initial state
    int currentState = 0;

    // algorithm that goes through entire string
    for(int i = 0; i < input.length(); i++) {
        char c = input[i];
        currentState = dfsmChart[currentState][charToInt(c)];
    }

    // if current state is an accepting state, program returns true
    for(int z = 0; z < acceptedStates.size(); z++) {
        if(currentState == acceptedStates[z]) 
            return true;
    }

    // proram is not in an accepting state
    return false;

}

// adds characters accepted by language
void DFSM::addCharacter(char x) {
    characters.push_back(x);
}

// sets the amount of states in the DFSM
void DFSM::setStates(int x) {
    stateCount = x;
}

// stores accepted states inside of a vector
void DFSM::addAcceptingState(int x) {
    acceptedStates.push_back(x);
}

// private helper function: converts character to integer co-ordinate point and stores it
int DFSM::charToInt(char c) {

    int result;
    
    // uses index of the character vector to determine co-ordinate value
    for(int i = 0; i < characters.size(); i++) {
        if(c == characters[i]) {
            result = i;
            break;
        }
    }

    return result;

}

// x = current state, y = character, z = target state
void DFSM::addPath(int x, char y, int z) {
    dfsmChart[x][charToInt(y)] = z;
}

// displays chart to console
void DFSM::printChart() {

    cout << "Row and Column Chart" << endl << endl;

    cout << "  ";

    for(int i = 0; i < characters.size(); i++) {
        cout << characters[i] << " ";
    }

    cout << endl;

    for(int j = 0; j < stateCount; j++) {
        cout << j << " ";
        for(int f = 0; f < characters.size(); f++) {
            cout << dfsmChart[j][f] << " ";
        }
        cout << endl;
    }

}