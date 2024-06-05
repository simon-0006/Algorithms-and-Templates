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

typedef tuple<ll, ll, ll> State; /* Distance, Node, Previous */

const ll INF = 1e18;
const int infP = 1e9 + 9;

#define eb emplace_back;
#define cinVec(vec)  { for (int i = 0; i < vec.size(); i++) cin >> vec[i]; }
#define coutVec(vec) { for (int i = 0; i < vec.size(); i++) cout << vec[i] << " "; cout << endl; }

// for debug
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

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
