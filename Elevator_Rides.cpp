#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "./codeforces/debug.hpp"
#endif

typedef long long int ll;
typedef vector<int> vint;
typedef vector<ll> vlong;

#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x;
    cin >> n >> x;
    vlong w(n);
    for (ll &i : w)
        cin >> i;
    vint dp(1 << n, INT_MAX);
    vlong left(1 << n, LONG_MAX);
    for (int i = 0; i < n; i++)
    {
        left[1 << i] = x - w[i];
        dp[1 << i] = 1;
    }
    left[0] = 0;
    dp[0] = 0;
    int S = 1 << n;
    for (int mask = 1; mask < S; mask++)
    {
        for (int i = 0; i < n; i++)
        {
            int a = 1 << i;
            if ((mask & a) == 0)
                continue;

            int t = dp[mask ^ a];

            ll l = left[mask ^ a];
            if (l >= w[i])
            {
                l -= w[i];
            }
            else
            {
                t++;
                // l = max(l, x - w[i]);
                l = x - w[i];
            }

            if (t < dp[mask])
            {

                dp[mask] = t;
                left[mask] = l;
            }
            if (t == dp[mask])
                left[mask] = max(l, left[mask]);
        }
    }
    // for (ll i : left)
    //     cout << i << ' ';
    // cout << endl;
    cout << dp.back();
}