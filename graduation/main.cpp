#include <iostream>
using namespace std;

int color(char x){
    return x - 'A';
}

int main() {
    int lines, columns, classes;
    cin >> lines >> columns >> classes;

    char lineup[lines][columns];
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> lineup[i][j];
        }
    }

    bool assigned_color[classes];
    int colors = 0;
    for (int i = 0; i < columns; ++i) {
        bool add_new = true;

        for (int j = 0; j < lines; ++j) {
            if (assigned_color[color(lineup[j][i])]) {
                add_new = false;
            }
        }

        if(add_new){
            colors++;
        }

        for (int j = 0; j < lines; ++j) {
            assigned_color[color(lineup[j][i])] = true;
        }
    }

    cout << colors << endl;
}