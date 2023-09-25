#include <iostream>
#include <sstream>
#include <vector>
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

void moveLEFT(vector<vector<int>> game_grid){
    for (int i = 0; i < 4; i++) {
        int counter = 0; int location = -1;

        for (int j = 0; j < 4; j++) {
            if(game_grid[i][j] == 0) {
                counter++;
                if (counter == 1) location = j;
            }
            else if (game_grid[i][j] != 0 && location != -1){
                game_grid[i][location] = game_grid[i][j];
                game_grid[i][j] = 0;
                location = j;
                counter = 0;
            }
        }

        for (int j = 0; j < 3; j++) {
            if (game_grid[i][j] != 0 && game_grid[i][j] == game_grid[i][j + 1])
            {
                game_grid[i][j] = game_grid[i][j] * 2;
                for (int k = j+1; k < 3; k++) {
                    game_grid[i][k] = game_grid[i][k + 1];
                }
                game_grid[i][3] = 0;
            }
        }
    }

    //Print new grid
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << game_grid[i][j] << " ";
        }
        cout << endl;
    }
}


void moveRIGHT(vector<vector<int>> game_grid){
    for (int i = 0; i < 4; i++) {
        int counter = 0; int location = -1;

        for (int j = 3; j > -1; j--) {
            if(game_grid[i][j] == 0) {
                counter++;
                if (counter == 1) location = j;
            }
            else if (game_grid[i][j] != 0 && location != -1){
                game_grid[i][location] = game_grid[i][j];
                game_grid[i][j] = 0;
                location = j;
                counter = 0;
            }
        }

        for (int j = 3; j > 0; j--) {
            if (game_grid[i][j] != 0 && game_grid[i][j] == game_grid[i][j - 1])
            {
                game_grid[i][j] = game_grid[i][j] * 2;
                for (int k = j-1; k > 0; k--) {
                    game_grid[i][k] = game_grid[i][k - 1];
                }
                game_grid[i][0] = 0;
            }
        }
    }

    //Print new grid
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << game_grid[i][j] << " ";
        }
        cout << endl;
    }
}


void moveUP(vector<vector<int>> game_grid){
    for (int j = 0; j < 4; j++) {
        int counter = 0; int location = -1;

        for (int i = 0; i < 4; i++) {
            if(game_grid[i][j] == 0) {
                counter++;
                if (counter == 1) location = i;
            }
            else if (game_grid[i][j] != 0 && location != -1){
                game_grid[location][j] = game_grid[i][j];
                game_grid[i][j] = 0;
                location = i;
                counter = 0;
            }
        }

        for (int i = 0; i < 3; i++) {
            if (game_grid[i][j] != 0 && game_grid[i][j] == game_grid[i + 1][j])
            {
                game_grid[i][j] = game_grid[i][j] * 2;
                for (int k = i+1; k < 3; k++) {
                    game_grid[k][j] = game_grid[k + 1][j];
                }
                game_grid[3][j] = 0;
            }
        }
    }

    //Print new grid
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << game_grid[i][j] << " ";
        }
        cout << endl;
    }
}


void moveDOWN(vector<vector<int>> game_grid){
    for (int j = 0; j < 4; j++) {
        int counter = 0; int location = -1;

        for (int i = 3; i > -1; i--) {
            if(game_grid[i][j] == 0) {
                counter++;
                if (counter == 1) location = i;
            }
            else if (game_grid[i][j] != 0 && location != -1){
                game_grid[location][j] = game_grid[i][j];
                game_grid[i][j] = 0;
                location = i;
                counter = 0;
            }
        }

        for (int i = 3; i > 0; i--) {
            if (game_grid[i][j] != 0 && game_grid[i][j] == game_grid[i - 1][j])
            {
                game_grid[i][j] = game_grid[i][j] * 2;
                for (int k = i - 1; k > 0; k--) {
                    game_grid[k][j] = game_grid[k - 1][j];
                }
                game_grid[0][j] = 0;
            }
        }
    }

    //Print new grid
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << game_grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> game_grid = {};

    for (int i = 0; i < 4; ++i) {
        //Get the input line
        string input_line = {};
        getline(cin, input_line);

        //Split it and push to vector
        vector<string> input = split(input_line, ' ');
        vector<int> intInput;

        for (int j = 0; j < 4; ++j) {
            intInput.push_back(stoi(input[j]));
        }

        game_grid.push_back(intInput);
    }

    //The players move
    string stringmove = {};
    getline(cin, stringmove);
    int player_move = stoi(stringmove);

    //-- Play the move --
    switch (player_move) {
        case 0:{moveLEFT(game_grid); break;}
        case 1:{moveUP(game_grid); break;}
        case 2:{moveRIGHT(game_grid); break;}
        case 3:{moveDOWN(game_grid); break;}
    }
}
