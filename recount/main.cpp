#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> candidates;

    string vote;
    while (getline(cin, vote)){
        if (vote == "***") break;
        if (candidates.find(vote) == candidates.end()){
            candidates[vote] = 1;
        } else {
            candidates[vote]++;
        }
    }

    bool tie; pair<string, int> winner("", 0);
    for(auto& it: candidates){
        if(winner.second < it.second){
            winner = it;
            tie = false;
        } else if (winner.second == it.second){
            tie = true;
        }
    }

    if (tie) cout << "Runoff!" << endl;
    else cout << winner.first << endl;
}
