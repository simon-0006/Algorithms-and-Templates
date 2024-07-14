#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

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

ll inv(ll a) {
    return binpow(a, mod-2, mod);
}

/* copied from Codeforce Round 957: Solution to Ultra-Meow */

ll add(ll a, ll b) {
    if (a + b >= mod)
        return a + b - mod;
    return a + b;
}

ll sub(ll a, ll b) {
    if (a < b)
        return a + mod - b;
    return a - b;
}

ll mul(ll a, ll b) {
    return a * b % mod;
}

/* Precomputing Factorials f and its Inverses r */

const int N = 15000;
int f[N], r[N];

void precalc() {
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = mul(f[i - 1], i);
    r[N - 1] = inv(f[N - 1]);
    for (int i = N - 2; i > -1; i--)
        r[i] = mul(r[i + 1], i + 1);
}

int choose(int n, int k) {
    if (n < 0 || k < 0 || n < k)
        return 0;
    return mul(f[n], mul(r[k], r[n - k]));
}
