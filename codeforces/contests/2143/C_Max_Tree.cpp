
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

bool vis[(int)5e5 + 5];
void postDfs(vector<vector<int>> &g, vint &res, int node)
{
    if (vis[node])
        return;
    vis[node] = true;
    for (int t : g[node])
        postDfs(g, res, t);
    res.push_back(node);
}

vector<int> topologicalSort(vector<vector<int>> &g)
{
    vector<int> inc(g.size(), 0);
    for (auto &ff : g)
        for (int f : ff)
            inc[f]++;
    vector<int> res;
    for (int i = 1; i < g.size(); i++)
        if (inc[i] == 0)
            postDfs(g, res, i);
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        memset(vis, false, sizeof(vis));
        int n;
        cin >> n;
        vector<vint> g(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            ll u, v, x, y;
            cin >> u >> v >> x >> y;
            if (x <= y)
                g[u].push_back(v);
            else
                g[v].push_back(u);
        }
        vint gg = topologicalSort(g);
        vint res(n + 1);
        for (int i = 0; i < n; i++)
        {
            int v = gg[i];
            res[v] = i + 1;
        }
        for (int i = 1; i <= n; i++)
            cout << res[i] << ' ';
        cout << endl;
    }
}