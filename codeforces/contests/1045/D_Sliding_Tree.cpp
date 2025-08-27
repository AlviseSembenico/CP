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
void dists(const vector<vint> &g, const vint &inc, vint &dist, vint &par)
{
    int n = (int)g.size() - 1;
    vector<char> seen(n + 1, 0);
    vector<int> s;
    for (int i = 1; i <= n; i++)
        if (inc[i] == 1)
        {
            s.push_back(i);
            seen[i] = 1;
            dist[i] = 0;
            par[i] = -1;
        }
    int d = 0;
    while (!s.empty())
    {
        vector<int> ns;
        for (int u : s)
        {
            dist[u] = d;
            for (int v : g[u])
                if (!seen[v])
                {
                    seen[v] = 1;
                    par[v] = u;
                    ns.push_back(v);
                }
        }
        s.swap(ns);
        d++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vint> g(n + 1);
        vint inc(n + 1, 0);
        loop0(n - 1)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
            inc[a]++;
            inc[b]++;
        }

        vint dist(n + 1, 0), par(n + 1, -1);
        dists(g, inc, dist, par);

        // prune to branching core
        vector<int> deg = inc;
        vector<char> alive(n + 1, 1);
        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (deg[i] == 1 && inc[i] < 3)
                q.push(i);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (!alive[u])
                continue;
            alive[u] = 0;
            for (int v : g[u])
                if (alive[v])
                {
                    if (--deg[v] == 1 && inc[v] < 3)
                        q.push(v);
                }
        }

        int b = -1, c = -1;
        for (int u = 1; u <= n; u++)
            if (alive[u] && inc[u] >= 3)
            {
                int coredeg = 0, nb = -1;
                for (int v : g[u])
                    if (alive[v])
                    {
                        coredeg++;
                        nb = v;
                    }
                if (coredeg == 1)
                {
                    b = u;
                    c = nb;
                    break;
                }
            }

        if (b == -1)
        { // single branching node
            for (int u = 1; u <= n; u++)
                if (alive[u] && inc[u] >= 3)
                {
                    b = u;
                    break;
                }
            if (b == -1)
            {
                cout << -1 << '\n';
                continue;
            }           // already path
            c = par[b]; // step toward nearest leaf
            int a = -1;
            for (int v : g[b])
                if (v != c)
                {
                    a = v;
                    break;
                }
            cout << a << " " << b << " " << c << "\n";
        }
        else
        {
            int a = -1;
            for (int v : g[b])
                if (v != c)
                {
                    a = v;
                    break;
                }
            cout << a << " " << b << " " << c << "\n";
        }
    }
}
