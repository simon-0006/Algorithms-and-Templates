#include <bits/stdc++.h>

typedef long long ll;
typedef vector<ll> vll;

using namespace std;

// MOD inverse = binpow(a, MOD - 2, MOD);
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// Change Bounds:
ll n;
ll tar;
vll vec;
// -------------
ll binarySearch() {
    ll l = 0;
    ll r = n - 1;
    while (l <= n) {
        ll mid = (l + r) / 2;
        if (vec[mid] <= tar) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return r;
}
