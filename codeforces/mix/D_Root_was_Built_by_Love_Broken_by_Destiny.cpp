
#include <bits/stdc++.h>

using namespace std;

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

bool visited[(int)2e5 + 5];
bool checked[(int)2e5 + 5];

bool check(vector<vector<int>> &g, int node, int parent)
{
    if (visited[node])
        return true;
    if (checked[node])
        return false;

    checked[node] = true;
    visited[node] = true;
    for (auto t : g[node])
    {
        if (t == parent)
            continue;
        if (check(g, t, node))
            return true;
    }
    visited[node] = false;
    return false;
}

bool contains_cycle(vector<vector<int>> &g)
{
    fill_n(checked, g.size() + 5, false);
    fill_n(visited, g.size() + 5, false);
    for (int i = 0; i < (int)g.size(); i++)
    {
        if (!checked[i])
        {
            if (check(g, i, -1))
                return true;
        }
    }
    return false;
}
bool check2(vector<vint> &g, vint &col)
{
    bool c = true;
    vint s = {1};
    while (!s.empty())
    {
        vint ns;
        for (int n : s)
        {
            for (int to : g[n])
            {
                if (col[to] == c)
                    return true;
                if (col[to] != -1)
                    continue;
                col[to] = !c;
                ns.push_back(to);
            }
        }
        s = ns;
        c = !c;
    }
    return false;
}
inline ll mod_mul(ll a, ll b, ll mod)
{
    ll result = 0;
    a %= mod;
    while (b > 0)
    {
        if (b & 1)
            result = (result + a) % mod;
        a = (a * 2) % mod;
        b >>= 1;
    }
    return result;
}
ll mod = 1e9 + 7;
ll factorial(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    ll res = 1;
    for (int i = 1; i <= n; i++)
        res = mod_mul(res, i, mod);
    return res;
}

ll count(vector<vint> &g, int n, int ma)
{
    vint to = g[n];
    visited[n] = true;
    int d = 0;
    ll res = 1;
    for (int t : to)
    {
        if (visited[t])
            continue;
        if (g[t].size() == 1)
            d++;
        else
        {
            if (ma <= 0)
                throw 11;
            res *= count(g, t, 1);
            res %= mod;
            ma--;
        }
    }
    if (d > 0)
        res = mod_mul(res, factorial(d), mod);
    // res *= factorial(d);
    // cout << n << ' ' << res << endl;
    return res;
}

ll comp(vector<vint> &g, int h)
{
    vint col(g.size(), -1);
    if (check2(g, col) || contains_cycle(g))
        return 0;
    fill_n(visited, g.size() + 5, false);
    ll res;
    bool found = false;
    for (int i = 1; i < g.size(); i++)
        if (g[i].size() != 1)
        {
            visited[i] = true;
            found = true;
            try
            {
                res = count(g, i, 2);
            }
            catch (int e)
            {
                return 0;
            }
            int dd = 0;
            int alive = 0;
            for (int d : g[i])
            {
                if (g[d].size() == 1)
                    dd++;
                else
                    alive++;
            }
            if (alive > 0)
                res *= 2;

            break;
        }
    if (!found)
        return 2;
    return res * 2 % mod;
}

void print_vector_2d(const vector<vector<int>> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << i << ": ";
        for (int x : v[i])
        {
            cout << x << " ";
        }
    }
    cout << "\n";
}
int main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int te = 0;
    while (t--)
    {
        te++;
        int h, b;
        cin >> h >> b;
        vector<vint> g(h + 1);
        loop0(b)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        // if (h > 50000)
        // cout << contains_cycle(g);
        cout << comp(g, h) << endl;
        // cout << "-------" << endl;
    }
}