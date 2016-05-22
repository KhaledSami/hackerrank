#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <limits>
using namespace std;

void BFS(const vector<vector<int>>& graph, int node, vector<int>& distance) {
    vector<bool> seen(graph.size(), false);
    queue<int> q;
    seen[node] = true;
    q.push(node);
    int level = 1;
    while (!q.empty()) {
        int cur_nodes = q.size();
        while (cur_nodes--) {
            node = q.front();
            q.pop();
            for (const auto& to : graph[node]) {
                if (seen[to]) continue;
                distance[to] = level * 6;
                seen[to] = true;
                q.push(to);
            }
        }
        level++;
    }
}

int main() {
    int t, n, m, x, y;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        vector<vector<int>> graph(n);
        while (m--) {
            scanf("%d %d", &x, &y);
            x--, y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        scanf("%d", &x);
        x--;
        vector<int> distance(n, numeric_limits<int>::max());
        BFS(graph, x, distance);
        string sep = "";
        for (int i = 0; i < n; i++) {
            if (i == x) continue;
            cout << sep;
            if (distance[i] == numeric_limits<int>::max()) {
                cout << -1;
            } else {
                cout << distance[i]; 
            }
             sep = " ";
        }
        cout << endl;
    }
    return 0;
}
// https://www.hackerrank.com/challenges/bfsshortreach
