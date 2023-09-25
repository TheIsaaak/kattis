#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

char charify(int num) {
    return (char) num + 'A' - 1;
}

bool check4move(int x, int y) {
    return !(x > 8 || x < 1 || y > 8 || y < 1);
}

//The idea here is that every possible position can be reached with 2 moves or less.
//By checking all possible moves from the start position and all moves from the end position,
//we can always find a path.
int main() {
    string problems;
    getline(cin, problems);

    //Loop thorugh every problem
    for (int i = 0; i < stoi(problems); ++i) {
        pair<int, int> start[stoi(problems)];
        pair<int, int> end[stoi(problems)];
        vector<pair<int, int>> start_moves;
        vector<pair<int, int>> end_moves;
        string move;
        char x, y;

        getline(cin, move);
        stringstream ss(move);

        //Convert the char to int to handle later
        ss >> x;
        start[i].first = x - 'A' + 1;
        ss >> start[i].second;

        ss >> y;
        end[i].first = y - 'A' + 1;
        ss >> end[i].second;

        if(start[i] == end[i]){ // If start and end is the same
            cout << "0 " << charify(start[i].first) << " " << start[i].second << endl;
            continue;
        }

        //Get available moves from start
        for(int j = 0; j < 9; j++) {
            if(check4move(start[i].first + j, start[i].second + j)) {
                start_moves.emplace_back(start[i].first+j, start[i].second+j);
            }
            if(check4move(start[i].first + j, start[i].second - j)) {
                start_moves.emplace_back(start[i].first+j, start[i].second-j);
            }
            if(check4move(start[i].first - j, start[i].second + j)) {
                start_moves.emplace_back(start[i].first-j, start[i].second+j);
            }
            if(check4move(start[i].first - j, start[i].second - j)) {
                start_moves.emplace_back(start[i].first-j, start[i].second-j);
            }
        }

        //Check if end position is in start positions available moves
        bool found_move = false;
        for(auto & start_move : start_moves) {
            if(start_move.first == end[i].first &&
               start_move.second == end[i].second) {
                cout << "1 " << charify(start[i].first) << " " << start[i].second << " "
                     << charify(end[i].first) << " " << end[i].second << endl;
                found_move = true;
            }
        }
        if(found_move) {
            continue;
        }

        //No? Do the same for end position
        //Find all moves possible from end position
        for(int j = 0; j < 9; j++) {
            if(check4move(end[i].first+j, end[i].second+j)) {
                end_moves.emplace_back(end[i].first+j, end[i].second+j);
            }
            if(check4move(end[i].first + j, end[i].second - j)) {
                end_moves.emplace_back(end[i].first+j, end[i].second-j);
            }
            if(check4move(end[i].first - j, end[i].second + j)) {
                end_moves.emplace_back(end[i].first-j, end[i].second+j);
            }
            if(check4move(end[i].first - j, end[i].second - j)) {
                end_moves.emplace_back(end[i].first-j, end[i].second-j);
            }
        }

        //Check if start and end position share paths
        //If they don't have any, it's impossible
        int move_found = -1;
        for(int j = 0; j < start_moves.size(); j++) {
            for(auto & end_move : end_moves) {
                if(start_moves[j].first == end_move.first &&
                   start_moves[j].second == end_move.second) {
                    move_found = j;
                }
            }
        }
        
        if(move_found == -1) {
            cout << "Impossible" << endl;
            continue;
        }

        //Print the path!
        pair<int,int> mid = start_moves[move_found];
        cout << "2 " << charify(start[i].first) << " " << start[i].second << " "
             << charify(mid.first) << " " << mid.second << " "
             << charify(end[i].first) << " " << end[i].second << endl;
    }
}