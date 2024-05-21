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

vll z_function(string &s) {
    int n = s.size();
    vll z(n); z[0] == 0;
    ll l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (i < r) {
            z[i] = std::min(r-i+1,z[i-l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
