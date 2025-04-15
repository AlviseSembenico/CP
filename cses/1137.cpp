#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
#include <climits>
#include <algorithm>

using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "../codeforces/debug.hpp"
#endif

typedef long long int ll;

void eulerPath(ll node, vector<vector<ll>> &graph, vector<ll> &res, vector<ll> &vals, vector<ll> &start, vector<ll> &end, bool seen[])
{
    if (seen[node])
        return;
    seen[node] = true;
    res.push_back(vals[node]);
    start[node] = res.size() - 1;
    for (ll child : graph[node])
        eulerPath(child, graph, res, vals, start, end, seen);
    end[node] = res.size() - 1;
}

void build(vector<ll> &t, vector<ll> &a, ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(t, a, v * 2, tl, tm);
        build(t, a, v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

ll sum(vector<ll> &t, ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return 0LL;
    if (l == tl && r == tr)
    {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return sum(t, v * 2, tl, tm, l, min(r, tm)) + sum(t, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(vector<ll> &t, ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if (tl == tr)
    {
        t[v] = new_val;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(t, v * 2, tl, tm, pos, new_val);
        else
            update(t, v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q;
    cin >> n >> q;
    vector<ll> nodes(n + 1);
    for (ll i = 0; i < n; i++)
        cin >> nodes[i + 1];
    vector<vector<ll>> edges(n + 1);
    for (ll i = 0; i < n - 1; i++)
    {
        ll f, t;
        cin >> f >> t;
        edges[f].push_back(t);
        edges[t].push_back(f);
    }

    vector<ll> euler;
    vector<ll> start(n + 1);
    vector<ll> end(n + 1);
    bool seen[(int)2e5 + 10];
    fill_n(seen, (int)2e5 + 10, false);
    eulerPath(1, edges, euler, nodes, start, end, seen);

    vector<ll> segtree(4 * euler.size());
    build(segtree, euler, 1, 0, euler.size() - 1);

    for (ll i = 0; i < q; i++)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll s, x;
            cin >> s >> x;
            update(segtree, 1, 0, euler.size() - 1, start[s], x);
        }
        else
        {
            ll s;
            cin >> s;
            ll res = sum(segtree, 1, 0, euler.size() - 1, start[s], end[s]);
            cout << res << endl;
        }
    }
}