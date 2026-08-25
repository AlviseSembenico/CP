#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const int MOD = 998244353;

inline ll modPow(ll x, ll e, ll m = MOD)
{
    ll r = 1;
    while (e)
    {
        if (e & 1)
            r = r * x % m;
        x = x * x % m;
        e >>= 1;
    }
    return r;
}

inline ll mod_inv(ll a)
{
    return modPow(a, MOD - 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<array<int, 4>> v(n);
    ll num = 1, den = 1;
    for (int i = 0; i < n; i++)
    {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        v[i] = {l, r, p, q};
        num = num * (q - p) % MOD;
        den = den * q % MOD;
    }

    vector<ll> dp1(m + 1, 0);
    dp1[0] = num * mod_inv(den) % MOD;
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        int from = v[i][0] - 1;
        int to = v[i][1];
        int p = v[i][2];
        int q = v[i][3];

        ll alpha = (ll)p * mod_inv((q - p + MOD) % MOD) % MOD;
        ll add = dp1[from] * alpha % MOD;
        dp1[to] = (dp1[to] + add) % MOD;
    }

    cout << dp1[m] << "\n";
    return 0;
}
