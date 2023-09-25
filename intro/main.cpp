#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
    //Data
    vector<string> votes;
    string vote;

    //Input all the votes
    cout << "Enter votes: " << endl;
    while(true)
    {
        getline(cin, vote);
        if(vote == "***"){
            break;}

        votes.insert(votes.end(), vote);
    }

    //Print the votes for testing
    for (const auto & vote : votes) {
        for (const auto & vote : votes) {
            
        }
    }

    return 0;
}
