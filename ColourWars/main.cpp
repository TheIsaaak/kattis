#include <iostream>
#include <sstream>
#include <vector>
#include "map"

using namespace std;

vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }
    return result;
}

int main() {
    string students;
    getline(cin, students);

    //Get the input line
    string input_line = {};
    getline(cin, input_line);
    //Split it and push to vector
    vector<string> input = split(input_line, ' ');

    map<string, int> votes;
    int possible_students = 0;
    for (int i = 0; i < stoi(students); ++i) {
        if (votes[input[i]] > stoi(input[i])) {
            votes[input[i]] = 0;
        }

        if (votes[input[i]] == 0) {
            possible_students += stoi(input[i]) + 1;
            votes[input[i]] = 1;
        }else{
            votes[input[i]]++;
        }
    }

    cout << possible_students << endl;
}