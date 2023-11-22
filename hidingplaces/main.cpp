#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Chessboard{
private:
    int inf = 1 << 15;

    static bool range(int i, int j) {
        return i >= 0 && j >= 0 && i < 8 && j < 8;
    }

    static void bfs(vector<vector<int>>& dist, int start_i, int start_j) {
        queue<pair<int,int>> q;
        q.emplace(start_i, start_j);
        dist[start_i][start_j] = 0;

        vector<int> dx = {1,2,2,1,-1,-2,-2,-1};
        vector<int> dy = {-2,-1,1,2,2,1,-1,-2};

        while(!q.empty()) {
            int current_i = q.front().first;
            int current_j = q.front().second;
            q.pop();

            for(int k = 0; k < 8; k++) {
                int next_i = current_i + dx[k];
                int next_j = current_j + dy[k];

                if(!range(next_i, next_j)) continue;
                if(dist[next_i][next_j] > dist[current_i][current_j] + 1) {
                    dist[next_i][next_j] = dist[current_i][current_j] + 1;
                    q.emplace(next_i, next_j);
                }
            }
        }
    }

public:
    void play(string move) const{
        vector<vector<int>> dist(8, vector<int>(8,inf));
        bfs(dist, move[0]-'a', move[1]-'1');

        // Find longest dist
        int far = 0;
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                far = max(far, dist[i][j]);
            }
        }
        cout << far << " ";

        // Find all at that dist
        vector<string> ans;
        for(int j = 7; j >= 0; j--) {
            for(int i = 0; i < 8; i++) {
                if(dist[i][j] == far) {
                    string here;
                    here += i + 'a';
                    here += j + '1';
                    cout << here << " ";
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; ++i) {
        Chessboard board;
        string move;

        cin >> move;
        board.play(move);
    }
}
