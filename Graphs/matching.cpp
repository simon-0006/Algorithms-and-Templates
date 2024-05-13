#include <bits/stdc++.h>

using namespace std;
#define NIL 0
#define INF INT_MAX

/** Heiratssatz: Satz von Hall
 * Ein bipartiter Graph G = (A \uplus B, E) enthält 
 * ein Matching M der Kardinalität |M| = |A| iff
 * für alle Teilmengen X von A: |X| <= |N(X)|
*/

class BipGraph {
    int n,m; // Size of both parts of BipGraph

    vector<int> *adj;
    int *pairU, *pairV, *dist;
    
public:
    BipGraph(int n, int m);
    void addEdge(int u, int v);

    // Returns true if there is an augmenting path
    bool bfs();

    // Adds augmenting path if there is one beginning with u
    bool dfs(int u);

    // Returns size of maximum matching
    int hopcroftKarp();

};

int BipGraph::hopcroftKarp() {
    pairU = new int[m + 1];
    pairV = new int[n + 1];
    dist = new int[m + 1];

    for (int u=0; u<=m; u++) pairU[u] = NIL;
    for (int v=0; v<=n; v++) pairV[v] = NIL;

    int result = 0;

    while (bfs()) {
        for (int u=1; u<=m; u++) {
            if (pairU[u]==NIL && dfs(u)) result++;
        }
    }
    return result;
}

bool BipGraph::dfs(int u) {
    if (u == NIL) return true;

    vector<int>:: iterator i;
    for (i=adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i;
        if (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v]) == true) {
            pairV[v] = u;
            pairU[u] = v;
            return true;
        }
    }

    // No augmenting path beginning with u
    dist[u] = INF;
    return false;
}

bool BipGraph::bfs() {
    queue<int> q;

    // add all free vertices and init dist Array
    for (int u=1; u<=m; u++) {
        if (pairU[u]==NIL) {
            dist[u] = 0;
            q.push(u);
        } else {
            dist[u] = INF;
        }
    }

    dist[NIL] = INF;

    // q only going through vertices on left side
    while (!q.empty()) {
        int u = q.front(); q.pop();

        // If Node is not NIL and can provide shorter path to NIL
        if (dist[u] < dist[NIL]) {

            // Get adj vertices
            vector<int>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i) {
                int v = *i;

                // If pair of v is not considered so far
                if (dist[pairV[v]] == INF) {
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
    }

    return (dist[NIL] != INF);
}

void BipGraph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

// Constructor
BipGraph::BipGraph(int n, int m) {
    this->n = n;
    this->m = m;
    this->adj = new vector<int>[m + 1]; // problem when not sorted
}

int main() {

    BipGraph g(4, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 1);
    g.addEdge(3, 2);
    g.addEdge(4, 2);
    g.addEdge(4, 4);
 
    cout << "Size of maximum matching is " << g.hopcroftKarp();
    return 0;
}