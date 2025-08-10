
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
typedef vector<int> vint;
typedef vector<ll> vlong;

#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))

struct DSU
{
    vint e;
    void init(int N) { e = vint(N, -1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y)
    {
        x = get(x), y = get(y);
        if (x == y)
            return 0;
        if (e[x] > e[y])
            swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pil>> g(n);
    priority_queue<vlong> p;
    while (m--)
    {
        int f, t;
        ll w;
        cin >> f >> t >> w;
        f--;
        t--;
        g[f].push_back(make_pair(t, w));
        g[t].push_back(make_pair(f, w));
        p.push({-w, f, t});
    }
    DSU d;
    d.init(n);
    ll res = 0;
    while (d.size(0) != n)
    {
        if (p.empty())
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
        vlong v = p.top();
        p.pop();
        if (d.sameSet(v[1], v[2]))
            continue;
        res += v[0];
        d.unite(v[1], v[2]);
    }
    cout << -res;
}