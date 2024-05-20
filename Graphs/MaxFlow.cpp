#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

// Ford-Fulkerson Algorithm
class MaxFlow {
    int V;
    int s,t;
    int *par;
    // Restnetzwerk
    ll **adj;

public:
    void set(int V, vvll& graph);
    void deref();

    ll maxFlow(int s, int t);

    bool bfs();

}; 

void MaxFlow::set(int V, vvll& graph) {
    this->V = V;
    adj = new ll*[V];
    for (int i = 0; i < V; i++) {
        adj[i] = new ll[V];
    }

    for (int row = 0; row < V; row ++) {
        for (int col = 0; col < V; col ++ ) {
            adj[row][col] = graph[row][col];
        }
    }
}

void MaxFlow::deref() {
    for (int i = 0; i < V; i++) {
        delete[] adj[i];
    }
    delete[] adj;
}

bool MaxFlow::bfs() {
    par = new int[V];
    for (int i = 0; i < V; i++) par[i] = -1;
    par[0] = 0;
    queue<int> q; q.push(s);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nei = 0; nei < V; nei++) {
            if (adj[cur][nei] == 0 || par[nei] != -1) continue;
            par[nei] = cur;
            if (nei == t) return true;
            q.push(nei);

        }
    }

    return false;
}

ll MaxFlow::maxFlow(int s, int t) {
    ll mf = 0;
    this->s = s; this->t = t;

    while (bfs()) {
        ll min = LONG_MAX;
        for (int u = t; u != s; u = par[u]) {
            min = std::min(min, adj[par[u]][u]);
        }
        
        for (int u = t; u != s; u = par[u]) {
            int p = par[u];
            adj[p][u] -= min;
            adj[u][p] += min;
        }

        mf += min;
    }

    return mf;
}

int main() {
    int V = 6;
    vvll graph(V);
    for (vll& vec : graph) {
        for (int i = 0; i < V; i++) {
            vec.push_back(0);
        }
    }

    graph[0][0] =  0; graph[0][1] =  5; graph[0][2] =  7; graph[0][3] =  0; graph[0][4] =  0; graph[0][5] =  0;
    graph[1][0] =  0; graph[1][1] =  0; graph[1][2] =  7; graph[1][3] =  4; graph[1][4] =  0; graph[1][5] =  0;
    graph[2][0] =  0; graph[2][1] =  0; graph[2][2] =  0; graph[2][3] =  3; graph[2][4] =  3; graph[2][5] =  0;
    graph[3][0] =  0; graph[3][1] =  0; graph[3][2] =  0; graph[3][3] =  0; graph[3][4] =  4; graph[3][5] =  5;
    graph[4][0] =  0; graph[4][1] =  0; graph[4][2] =  0; graph[4][3] =  0; graph[4][4] =  0; graph[4][5] =  6;
    graph[5][0] =  0; graph[5][1] =  0; graph[5][2] =  0; graph[5][3] =  0; graph[5][4] =  0; graph[5][5] =  0;

    MaxFlow mf;
    mf.set(V, graph);
    cout << "The maximum possible flow is "
         << mf.maxFlow(0, 5) << endl;

    mf.deref();
 
    return 0;
}
