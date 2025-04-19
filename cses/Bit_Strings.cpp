#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "./codeforces/debug.hpp"
#endif

const int MOD = 1e9 + 7;

typedef long long int ll;
// Modular exponentiation
inline ll modPow(ll x, ll exp, ll mod)
{
    ll ans = 1;
    while (exp > 0)
    {
        if (exp & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        exp /= 2;
    }
    return ans;
}

inline ll mod_mul(ll a, ll b, ll mod)
{
    ll result = 0;
    a %= mod;
    while (b > 0)
    {
        if (b & 1)
            result = (result + a) % mod;
        a = (a * 2) % mod;
        b >>= 1;
    }
    return result;
}

// Benq template
struct mi
{
    ll v;
    explicit operator int() const { return v; }
    mi() { v = 0; }
    mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b)
{
    if ((a.v += b.v) >= MOD)
        a.v -= MOD;
    return a;
}
mi &operator-=(mi &a, mi b)
{
    if ((a.v -= b.v) < 0)
        a.v += MOD;
    return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p)
{
    assert(p >= 0);
    return modPow(a.v, p, MOD);
}
mi inv(mi a)
{
    assert(a.v != 0);
    return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << " ";
    }
    return os;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    mi res = pow(mi(2), n);
    cout << res.v;
}