
#include <iostream>
#include <vector>

using namespace std;

class DFSM {

    // # of states machine has
    int stateCount;

    // vector of characters accepted by language
    vector<char> characters;

    // vector of accepted states in language
    vector<int> acceptedStates;

    // 2d array
    int** dfsmChart;

    // private helper function: converts character to integer co-ordinate point and stores it
    int charToInt(char);

    public:

        DFSM();

        void addCharacter(char); // adds characters accepted by language
        void addPath(int, char, int); // creates path and puts it in the 2d array
        void setStates(int); // sets the amount of states in the DFSM
        void addAcceptingState(int); // stores accepted states inside of a vector
        bool isAccepted(string); // determines if the string is accepted by machine
        void buildMachine(); // initializes array
        void printChart(); // displays chart to console

};