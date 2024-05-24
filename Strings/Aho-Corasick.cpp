#include <bits/stdc++.h>
#include <unordered_set>

#include <iostream>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

typedef vector<int> vi;
typedef vector<vi> vvi;

const ll INF = 1e18;
const int infP = 1e9 + 9;

const int K = 26; /* Has to be adjusted if there are also upper case letters */

struct Vertex {
    int next[K];
    bool output = false;    /* Can be adjusted to an int */
    int p = -1;             /* Parent Vertex */
    char pch;               /* Character between parent and vertex */
    int link = -1;          /* Link to longest Suffix */
    int go[K];              /* Cache for transitinons */

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].output = true;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 