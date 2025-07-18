#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vint;
typedef vector<ll> vlong;

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
#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))
#define graph vector<vector<int>>

bool vis[(int)1e5 + 5];
void postDfs(vector<vector<int>> &g, vint &res, int node)
{
    if (vis[node])
        return;
    vis[node] = true;
    while (!g[node].empty())
    {
        int t = g[node].back();
        g[node].pop_back();
        postDfs(g, res, t);
    }
    res.push_back(node + 1);
}

vector<int> topologicalSort(vector<vector<int>> &g)
{
    vint inc(g.size(), 0);
    for (vint ff : g)
        for (int f : ff)
            inc[f] = 1;
    vint res;
    for (int i = 0; i < g.size(); i++)
        if (inc[i] == 0)
        {
            postDfs(g, res, i);
        }
    return res;
}

bool visited[(int)1e5 + 5];
bool checked[(int)1e5 + 5];
bool check(vector<vector<int>> &g, int node)
{
    if (visited[node])
        return true;
    if (checked[node])
        return false;

    checked[node] = true;
    visited[node] = true;
    for (auto t : g[node])
        if (check(g, t))
            return true;
    visited[node] = false;
    return false;
}
bool contains_cycle(vector<vector<int>> &g)
{
    vector<int> inc(g.size() + 5, 0);
    for (auto e : g)
    {
        for (int to : e)
            inc[to]++;
    }
    for (int i = 0; i < g.size(); i++)
        if (inc[i] == 0)
        {
            if (check(g, i))
                return true;
        }
    return accumulate(checked, checked + g.size(), 0) != g.size();
}

int main()
{
#ifdef MD
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vint> g(n);
    loop0(m)
    {
        int f, t;
        cin >> f >> t;
        f--;
        t--;
        g[f].push_back(t);
    }
    if (contains_cycle(g))
    {
        cout << "IMPOSSIBLE";
        exit(0);
    }
    vint res = topologicalSort(g);
    reverse(all(res));
    for (int i : res)
        cout << i << ' ';
}