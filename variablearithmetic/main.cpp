#include <iostream>
#include <unordered_map>
#include <sstream>
#include "vector"
using namespace std;

//Split the input on spaces
vector<string> splitStringBySpaces(const string& input) {
    vector<string> result;
    istringstream iss(input);
    string word;

    while (iss >> word) {
        result.emplace_back(word);
    }
    return result;
}

int main() {
    unordered_map<string, int> variables; //Store variables and their values

    string input;
    while (getline(cin, input)){
        if(input == "0"){ //Exit
            break;
        }

        vector<string> commands = splitStringBySpaces(input);

        //Return single commands
        if (size(commands) == 1){
            if(variables.find(commands[0]) != variables.end()){
                cout << variables[commands[0]] << endl;
            }else{
                cout << input << endl;
            }
            continue;
        }

        //Read commands
        if(commands[1] == "="){
            variables[commands[0]] = stoi(commands[2]);
        }else if(commands[1] == "+"){
            int sum = 0; vector<string> undefined = {};
            for (int i = 0; i < size(commands); i = i + 2) {
                if(isdigit(commands[i][0])){
                    sum += stoi(commands[i]);
                }else if(variables.find(commands[i]) == variables.end()) {
                    undefined.emplace_back(commands[i]);
                }else{
                    sum += variables[commands[i]];
                }
            }

            // Print the result
            if(sum != 0){
                cout << sum;
                for (int i = 0; i < size(undefined); ++i) {
                    cout << " + " << undefined[i];
                }
                cout << endl;
            }else{
                cout << undefined[0];
                for (int i = 1; i < size(undefined); ++i) {
                    cout << " + " << undefined[i];
                }
                cout << endl;
            }
        }
    }
}
