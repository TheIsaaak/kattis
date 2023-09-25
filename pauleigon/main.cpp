#include <iostream>
using namespace std;

int main() {
    //Get all the info
    int round, paul_score, opponent_score;
    cin >> round;
    cin >> paul_score;
    cin >> opponent_score;

    if ( ((paul_score + opponent_score) / round) % 2 == 0){
        cout << "paul";
    }else
    {cout << "opponent";}
}