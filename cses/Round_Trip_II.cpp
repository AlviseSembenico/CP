
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

vector<int> cycle;
bool visited[(int)1e5 + 5];
bool ons[(int)1e5 + 5];

int dfs_c(int node, vector<vint> &g)
{
    visited[node] = ons[node] = true;
    for (int to : g[node])
    {
        if (ons[to])
        {
            cycle.push_back(to);
            cycle.push_back(node);
            ons[to] = ons[node] = false;
            return 1;
        }
        if (!visited[to])
        {
            int res = dfs_c(to, g);
            if (res == 1)
            {
                cycle.push_back(node);
                if (ons[node])
                {
                    ons[node] = false;
                    return 1;
                }
                else
                {
                    return 2;
                }
            }
            if (res == 2)
            {
                ons[node] = false;
                return 2;
            }
        }
    }
    ons[node] = false;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vint> g(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    for (int i = 0; i < n; i++)
    {
        dfs_c(i, g);
        if (!cycle.empty())
        {
            reverse(all(cycle));
            cout << cycle.size() << endl;
            for (int i : cycle)
                cout << i + 1 << ' ';
            exit(0);
        }
    }
    cout << "IMPOSSIBLE";
}