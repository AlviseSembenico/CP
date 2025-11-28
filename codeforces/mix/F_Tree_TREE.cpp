
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
#define pb push_back
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<int> vint;
typedef vector<ll> vlong;

#define pb push_back
#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))

vint cache(2e5 + 5, 0);

int ssub(vector<vint> &g, int n, int p)
{
    if (cache[n] > 0)
        return cache[n];
    int r = 1;
    for (int to : g[n])
        if (to != p)
            r += ssub(g, to, n);
    cache[n] = r;
    return r;
}

void ccn(vector<vint> &g, vector<vint> &out, int node, int parent, int value, int tot)
{
    out[node].push_back(value);
    int rem = tot - value - 1;
    for (int to : g[node])
    {
        if (to == parent)
            continue;

        int sub = ssub(g, to, node);
        out[node].push_back(sub);
        ccn(g, out, to, node, tot - sub, tot);
    }
}

ll comp(vector<vint> &g, int n, int k)
{
    vector<vint> out(g.size(), vint());
    int s = 1;
    ccn(g, out, s, -1, 0, n);

    ll res = n;
    for (int i = 1; i <= n; i++)
    {
        vint v = out[i];
        ll tot = accumulate(all(v), 0);
        for (int s : v)
        {
            ll r = tot - s;
            if (r < k - 1)
                continue;
            res += s;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef CINPUT
    freopen("input.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vint> g(n + 5, vint());
        fill_n(cache.begin(), n + 2, 0);
        loop0(n - 1)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout << comp(g, n, k) << endl;
    }
}