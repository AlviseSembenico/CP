
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    ll mod = 998244353;
    cin >> t;
    ll dp[1005][2];
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        dp[0][1] = 1;

        int n;
        cin >> n;
        vint v1(n), v2(n);
        for (int &i : v1)
            cin >> i;
        for (int &i : v2)
            cin >> i;
        for (int i = 0; i < n; i++)
        {
            int ma = max(v1[i], v2[i]);
            int mi = min(v1[i], v2[i]);
            v1[i] = mi;
            v2[i] = ma;
        }

        for (int i = 1; i < n; i++)
        {
            int m = v1[i];
            ll res = 0;
            if (m >= v1[i - 1])
                res = dp[i - 1][0];
            if (m >= v2[i - 1])
                res += dp[i - 1][1];
            dp[i][0] = res % mod;

            m = v2[i];
            res = 0;
            if (m >= v1[i - 1] && v1[i] >= v2[i - 1])
                res = dp[i - 1][0];
            if (m >= v2[i - 1])
                res += dp[i - 1][1];
            dp[i][1] = res % mod;
        }

        cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << endl;
    }
}