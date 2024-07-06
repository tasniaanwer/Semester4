

/*Tasnia Anower Medha
  ID-210042124
  problem:L.L

*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> topologicalSort(int n, vector<vector<int>>& graph) {
    vector<int> inDegree(n + 1, 0);
    vector<vector<int>> adjList(n + 1);


    for (auto& edge : graph) {
        int u = edge[0], v = edge[1];
        adjList[u].push_back(v);
        inDegree[v]++;
    }


    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adjList[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
        }
    }

    return order;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        cin >> graph[i][0] >> graph[i][1];
    }

    vector<int> order = topologicalSort(n, graph);

    if (order.size() != n) {
        cout << "Sandro fails." << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            cout << order[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
