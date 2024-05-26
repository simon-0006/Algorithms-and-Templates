using namespace std;
typedef long long ll;

/** Property: lcm(a,b) = |ab|/gcd(a,b)*/
ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}
