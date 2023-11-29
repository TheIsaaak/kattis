#include <bits/stdc++.h>
using namespace std;

class Graph {
    int vertices;
    list<pair<int, int> >* edges;
    vector<int> repairShops;

public:
    explicit Graph(int V, int E) {
        vertices = V;
        edges = new list<pair<int,int>>[E];

    }

    void addEdge(int u, int v, int w) {
        edges[u].emplace_back(v, w);
    }

    void addRepairShop(int u) {
        repairShops.emplace_back(u);
    }

    void shortestPath(int src, int goal, int energy)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<> > priQueue;
        vector<int> dist(vertices, INT_MAX);
        vector<int> energyLeft(vertices, 0);

        priQueue.emplace(0, src);
        dist[src] = 0;
        int myEnergy;

        while (!priQueue.empty()) {
            int u = priQueue.top().second;
            priQueue.pop();

            list<pair<int, int> >::iterator i;
            for (i = edges[u].begin(); i != edges[u].end(); ++i) {
                int v = (*i).first;
                int weight = (*i).second;

                if(find(repairShops.begin(), repairShops.end(), u) != repairShops.end()) {
                    myEnergy = energy;
                }else{
                    myEnergy = energyLeft[u];
                }

                if (dist[v] >= dist[u] + weight) {
                    if(myEnergy - weight >= 0) {
                        myEnergy -= weight;
                        dist[v] = dist[u] + weight;
                        priQueue.emplace(dist[v], v);

                        //Energy left when at this node now
                        energyLeft[v] = myEnergy;
                    }
                }
            }
        }

        if (dist[goal-1] == INT_MAX){
            cout << "stuck";
        }else {
            cout << dist[goal - 1];
        }
    }
};

int main()
{
    int n, m, t, d;
    cin >> n >> m >> t >> d; //Take input
    n++;

    Graph graph(n, m); //Create graph

    //Take input for repair shops
    for (int i = 0; i < t; ++i)
    {
        int repairShop;
        cin >> repairShop;
        graph.addRepairShop(repairShop);
    }
    graph.addRepairShop(1);

    //Take input for edges/roads
    for (int i = 0; i < m; ++i)
    {
        int y, j, k;
        cin >> y >> j >> k;
        graph.addEdge(y, j, k);
    }

    //Find the shortest path!
    graph.shortestPath(1, n, d);
}