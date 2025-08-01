
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
typedef pair<int, int> pii;
typedef vector<ll> vlong;

#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define pp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))

ll dist[500 * 2 + 5][500 * 2 + 5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll mm = 1e18;
    for (int i = 0; i < 500 * 2 + 5; i++)
    {
        fill(dist[i], dist[i] + 500 * 2 + 5, mm);
        dist[i][i] = 0;
    }
    int n, m, q;
    cin >> n >> m >> q;
    loop0(m)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = dist[u][v];
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    loop0(q)
    {
        int f, t;
        cin >> f >> t;
        ll v = dist[f][t];
        if (v == mm)
            v = -1;
        cout << v << endl;
    }
}