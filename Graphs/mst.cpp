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

// Personal Comparator
class EdgeWeightCompare {
public:
    bool operator() (pair<ll, pair<int, int> >& one, pair<ll, pair<int, int> >& two) {
        // min
        return one.first > two.first;

        // max
        // return one.first < two.first;
    }
};

// Union Find
class UF {
    int n;
    int *par, *rank;

public:
    UF(int n) {
        this->n = n;
        par  = new int[n + 1];
        rank = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            par[i] = i;
            rank[i] = 1;
        }
    }

    int find(int v) {
        if (par[v] == v) return v;
        par[v] = find(par[v]);
        return par[v];
    }

    bool Union(int v, int u) {
        int parV = find(v);
        int parU = find(u);
        if (parV == parU) return false;
        if (rank[parV] > rank[parU]) {
            par[parU] = parV;
        } else if (rank[parU] > rank[parV]) {
            par[parV] = parU;
        } else {
            par[parV] = parU;
            rank[parU]++;
        }
        return true;
    }
};

class MyGraph {
    int n;
    vector<pair<ll, pair<int, int> > > edges;

public:
    MyGraph(int n);

    void addEdge(int v, int u, ll w);

    int kruskal();

};

MyGraph::MyGraph(int n) {
    this->n = n;
}

void MyGraph::addEdge(int v, int u, ll w) {
    this->edges.push_back(make_pair(w, make_pair(v, u)));
}

// returns -1 if not possible
int MyGraph::kruskal() {
    if (n == 1) return 0;

    UF uf(n);
    priority_queue<pair<ll, pair<int, int> >, vector<pair<ll, pair<int, int> > >, EdgeWeightCompare> pq;

    vector<pair<ll, pair<int, int> > >::iterator i;
    for (i=edges.begin(); i != edges.end(); ++i) { pq.push(*i); }

    int count = 0;
    int sum = 0;
    while (count < n - 1) {
        pair<ll, pair<int, int> > p = pq.top(); pq.pop();
        if (uf.Union(p.second.first, p.second.second)) {
            count++; sum += p.first;
        }
        if (count == n - 1) return sum;
    }
    return -1;

}


int main() {
    int t; cin >> t;
    while (t --) {
        int V,E; cin >> V >> E;
        MyGraph mg(V);
        while (E--) {
            int u,v,w;
            cin >> u >> v >> w;
            mg.addEdge(u, v, w);
        }
        cout << mg.kruskal() << endl;
    }
    return 0;
}
