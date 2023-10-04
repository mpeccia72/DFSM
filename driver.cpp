#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "DFSM.h"

using namespace std;

// reads input file data to DFSM object
void readFile(ifstream& fileInput, DFSM& machineInput);

int main() {

    /* NOTE: The program assumes "input.txt" has correct format. The program may
             run into errors if the format is not correct */


    // opens "input.txt"
    ifstream input("./input.txt");

    // program stops if it fails to open "input.txt"
    if(!input.is_open()) {
        cout << "File Opening Error! Please fix and restart.";
        exit(0);
    }

    // instantiation
    DFSM machine;

    // data is read to machine
    readFile(input, machine);

    // closes input file
    input.close();

    machine.printChart();
    cout << endl;

    while(true) {
        string userInput;
        cin >> userInput;
        if(machine.isAccepted(userInput)) cout << "Accepted" << endl;
        else cout << "Rejected" << endl;
    }
    
}

void readFile(ifstream& fileInput, DFSM& machineInput) {

    // the string "line" will have each line from input streamed into it
    string line;
    getline(fileInput, line);

    // lines 48 - 55 deal with grabbing data from line 1 (language characters)
    machineInput.addCharacter(line[0]);

    for(int a = 1; a < line.length(); a++) {
        if(line[a] == ',') {
            machineInput.addCharacter(line[a + 1]);
        }
    }

    // grabs # of states from line 2
    int states;
    fileInput >> states;

    // sets # of states in object
    machineInput.setStates(states);
    
    // since we have the # of characters and # of states, the machine can build the array
    machineInput.buildMachine();

    // skips down to line 3
    getline(fileInput, line);
    getline(fileInput, line);

    // lines 72 - 77 grab the accepting states from line 3 
    machineInput.addAcceptingState(line[0] - '0');

    for(int e = 1; e < line.length(); e++) {
        if(line[e] == ',') 
            machineInput.addAcceptingState(line[e + 1] - '0');
    }

    getline(fileInput, line);

    // vector to store path data from lines 4 to n
    vector<char> list;

    // the algoritm below grabs data from lines 4 to n to create DFSM paths (lines 85 - 112)
    for(int b = 0; b < states; b++) {

        list.push_back(line[1]);

        for(int c = 1; c < line.length(); c++) {
    
            if(line[c] == ')') {

            if(c + 3 < line.length()) 
                list.push_back(line[c + 3]);
            
            c += 3;

        }
            
        else if(line[c] == ',') 
            list.push_back(line[c + 1]);
        
    }

    for(int d = 0; d < list.size(); d += 3) {
        machineInput.addPath(list[d] - '0', list[d + 1], list[d + 2] - '0');
    }

        list.clear();
        getline(fileInput, line);

    }

} 