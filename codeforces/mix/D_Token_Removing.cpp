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
#define contains(v, x) (find(begin(v), end(v), x) != end(v))

const int N = 5000 + 5;
ll dp[N][N];

ll f(int i, int j, ll mod, int n)
{
    if (j < 0 || j > i)
        return 0;
    if (i == 0)
        return j == 0;
    if (dp[i][j] >= 0)
        return dp[i][j];
    ll res = f(i - 1, j - 1, mod, n);
    res += 1LL * (n - i + 1) * (j + 1) % mod * f(i - 1, j, mod, n) % mod;
    res %= mod;
    return dp[i][j] = res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        ll n, mod;
        cin >> n >> mod;
        ll res = 0;
        for (int j = 0; j <= n; j++)
            res = (res + f(n, j, mod, n)) % mod;
        cout << res << endl;
    }
}