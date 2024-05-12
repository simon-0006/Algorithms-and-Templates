#include <bits/stdc++.h>

using namespace std;

/** Heiratssatz: Satz von Hall
 * Ein bipartiter Graph G = (A \uplus B, E) enthält 
 * ein Matching M der Kardinalität |M| = |A| iff
 * für alle Teilmengen X von A: |X| <= |N(X)|
*/

class BipGraph {
    int n,m; // Size of both parts of BipGraph
    
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
    // TODO
}

bool BipGraph::dfs(int u) {
    // TODO
}

bool BipGraph::bfs() {
    // TODO
}

void BipGraph::addEdge(int u, int v) {
    // TODO
}

// Constructor
BipGraph::BipGraph(int n, int m) {
    this->n = n;
    this->m = m;
}

int main() {
    return 0;
}