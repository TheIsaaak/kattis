#include <iostream>
#include <queue>
using namespace std;

void Getit(int n, int m){
    vector<vector<pair<long double, int>>> adj(n);
    for(int i = 0; i < m; i++) {
        int n1, n2;
        long double w;
        cin >> n1 >> n2 >> w;
        adj[n1].emplace_back(w, n2);
        adj[n2].emplace_back(w, n1);
    }

    vector<bool> vis(n, false);
    vector<long double> dist(n, 0);

    priority_queue<pair<long double,int>> pq;
    pq.emplace(1,0);

    while(!pq.empty()) {
        int curr = pq.top().second;
        long double size = pq.top().first;
        pq.pop();

        if(vis[curr]) {
            continue;
        }
        vis[curr] = true;

        dist[curr] = size;

        for(auto i : adj[curr]) {
            int next = i.second;
            long double fact = i.first;
            pq.emplace(size * fact, next);
        }
    }

    cout << fixed;
    cout.precision(4);
    cout << dist[n] << endl;
}

int main() {
    while (true){
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break; //Quit if n and m are 0

        Getit(n, m);
    }
}
