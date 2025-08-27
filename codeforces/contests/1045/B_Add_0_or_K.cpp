#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "./codeforces/debug.hpp"
#endif

#ifndef ONLINE_JUDGE
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}
#else
// If not debugging, define deb as empty
#define deb(...)
#endif
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<int> vint;
typedef vector<ll> vlong;

#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))
int MOD = 1e9 + 7;
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        MOD = k + 1;
        mi invk = mi(MOD - 1);

        loop0(n)
        {
            int a;
            cin >> a;
            mi aa = a;
            mi r = (MOD - aa) * invk;
            cout << a + r.v * k << ' ';
        }
        cout << endl;
    }
}