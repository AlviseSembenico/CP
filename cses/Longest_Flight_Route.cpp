
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
typedef vector<int> vint;
typedef vector<ll> vlong;

#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))

int dp[(int)1e5 + 5];

int dfs_dp(int node, vector<vector<int>> &g, int dest)
{
    if (node == dest)
        return 0;
    if (dp[node] != 0)
        return dp[node];

    int res = -INT_MAX / 2;
    for (int to : g[node])
    {
        res = max(res, dfs_dp(to, g, dest) + 1);
    }
    dp[node] = res;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vint> g(n);
    fill(dp, dp + (int)1e5 + 5, 0);

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    int res = dfs_dp(0, g, n - 1);
    if (res < 0)
    {
        cout << "IMPOSSIBLE";
        exit(0);
    }
    int node = 0;
    cout << res + 1 << endl;
    while (node != n - 1)
    {
        cout << node + 1 << ' ';
        for (int to : g[node])
            if (dp[to] == dp[node] - 1)
            {
                node = to;
                break;
            }
    }
    cout << n;
}