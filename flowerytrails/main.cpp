#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

typedef pair<long long, long long> hotellet;
typedef unordered_map<long long, unordered_map<long long, long long>> tungsatan;

long long finnvekta(long long nodes, vector<vector<hotellet>>& graph, tungsatan& weights) {
    vector<bool> besokt(nodes, false);
    vector<long long> avstand(nodes, LLONG_MAX);

    priority_queue<hotellet, vector<hotellet>, greater<>> minHeap;
    minHeap.emplace(0, 0);
    avstand[0] = 0;

    vector<vector<hotellet>> shortestPaths(nodes);
    while (!minHeap.empty()) {
        long long currentNode = minHeap.top().second;
        minHeap.pop();

        if (besokt[currentNode]) continue;
        besokt[currentNode] = true;

        for (const auto& edge : graph[currentNode]) {
            long long edgeWeight = edge.first;
            long long nextNode = edge.second;

            if (avstand[currentNode] + edgeWeight < avstand[nextNode]) {
                avstand[nextNode] = avstand[currentNode] + edgeWeight;
                shortestPaths[nextNode].clear();
                shortestPaths[nextNode].emplace_back(avstand[nextNode], currentNode);
                minHeap.emplace(avstand[nextNode], nextNode);
            } else if (avstand[currentNode] + edgeWeight == avstand[nextNode]) {
                shortestPaths[nextNode].emplace_back(avstand[nextNode], currentNode);
            }
        }
    }

    besokt.assign(nodes, false);
    queue<long long> q;
    q.push(nodes - 1);

    long long totalWeight = 0;
    while (!q.empty()) {
        long long current = q.front();
        q.pop();

        if (besokt[current]) continue;
        besokt[current] = true;

        for (const auto& path : shortestPaths[current]) {
            totalWeight += weights[current][path.second];
            q.push(path.second);
        }
    }

    return totalWeight * 2;
}

int main() {
    long long numNodes, numEdges;
    cin >> numNodes >> numEdges;

    vector<vector<hotellet>> hallis(numNodes);
    tungsatan kantjaevel;

    for (int i = 0; i < numEdges; ++i) {
        long long node1, node2, weight;
        cin >> node1 >> node2 >> weight;

        hallis[node1].emplace_back(weight, node2);
        hallis[node2].emplace_back(weight, node1);

        kantjaevel[node1][node2] = kantjaevel[node2][node1] = min(kantjaevel[node1][node2] ? kantjaevel[node1][node2] : weight, weight);
    }

    cout << finnvekta(numNodes, hallis, kantjaevel) << endl;
    return 0;
}
