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

class myPairComp {
public:
    bool operator()(ii &first, ii &second) {
        /** Logic of Comparator
         * returns 1 <=> first < second (first is BEFORE second)
         * returns 0 <=> first > second (first is AFTER  second)
        */
       if (first.first < second.first) { return 1; } 
       else if (first.first > second.first) { return 0; } 
       else {
        if (first.second < second.second) { return 0; }
        else if (first.second >= second.second) { return 1; }
       }
    }
};


void sol(ll a, ll b) {
    cout << "Solution" << endl;
}


int main() {
    int t; cin >> t;
    int a,b;
    while (t--) {
        cin >> a >> b;
        sol(a, b);
    }
    return 0;
}
