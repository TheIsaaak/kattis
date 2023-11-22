#include <bits/stdc++.h>
using namespace std;

class Graph {
    int vertices;
    list<pair<int, int> >* edges;

public:
    explicit Graph(int V) {
        vertices = V;
        edges = new list<pair<int,int>>[V];
    }

    void addEdge(int u, int v, int w) {
        edges[u].emplace_back(v, w);
    }

    void shortestPath(int src, int goal)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<> > priQueue;
        vector<int> dist(vertices, INT_MAX);

        priQueue.emplace(0, src);
        dist[src] = 0;

        while (!priQueue.empty()) {
            int u = priQueue.top().second;
            priQueue.pop();

            if (u == goal) {
                break;
            }

            list<pair<int, int> >::iterator i;
            for (i = edges[u].begin(); i != edges[u].end(); ++i) {
                int v = (*i).first;
                int weight = (*i).second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    priQueue.emplace(dist[v], v);
                }
            }
        }

        if(dist[goal] == INT_MAX || dist[goal] < 0) {
            cout << "Impossible" << endl;
        } else {
            cout << dist[goal] << endl;
        }
    }
};

int main()
{
    while (true){
        int n = 0, m = 0, q = 0, s = 0;
        cin >> n >> m >> q >> s;

        if (n == 0 && m == 0 && q == 0 && s == 0) {
            break;
        }

        Graph graph(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph.addEdge(u, v, w);
        }

        for (int i = 0; i < q; ++i) {
            int y = 0;
            cin >> y;
            graph.shortestPath(s, y);
        }

        cout << endl;
    }
}