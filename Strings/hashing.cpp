#include <bits/stdc++.h>
#include <unordered_set>

#include <iostream>

using namespace std;
const int infP = 1e9 + 9;

typedef long long ll;

// Custom hash function for std::pair<int, int>
struct PairHash {
    size_t operator()(const pair<ll, ll>& p) const {
        size_t h1 = hash<ll>()(p.first);
        size_t h2 = hash<ll>()(p.second);
        return h1 ^ (h2 << 8); // Combine the hash values
    }
};

ll hashing(const string& s, ll& p, ll& m) { /* p = prime, m = modulo (usually: infP) */
    ll hash_value = 0;
    ll p_pow = 1;
    int idx = 0;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1)*p_pow)%m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}