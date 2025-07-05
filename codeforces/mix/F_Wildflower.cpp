#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0
#define range(a, b) for (int i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#if DEBUG
#define HAS_EXTRA 1
#include "./codeforces/debug.hpp"
#endif

typedef long long int ll;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << " ";
    }
    return os;
}

ll mod = 1e9 + 7;

int number_leaves(vector<vector<int>> &g, int u, int p)
{
    int count = 0;
    for (int v : g[u])
    {
        if (v != p)
        {
            count += number_leaves(g, v, u);
        }
    }
    return count == 0 ? 1 : count;
}

ll mod_pow(ll base, ll exp, ll mod)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int path_length(vector<vector<int>> &g, int u, int p)
{
    int max_length = 0;
    for (int v : g[u])
    {
        if (v != p)
        {
            max_length = max(max_length, path_length(g, v, u));
        }
    }
    return max_length + 1;
}

bool reach_zero(vector<vector<int>> &g, int u, int p)
{
    if (u == 0)
    {
        return true;
    }
    for (int v : g[u])
    {
        if (v != p)
        {
            if (reach_zero(g, v, u))
            {
                return true;
            }
        }
    }
    return false;
}

ll compute(vector<vector<int>> &g)
{
    int nl = number_leaves(g, 0, -1);
    if (nl > 2)
    {
        return 0;
    }
    if (nl == 1)
    {
        return mod_pow(2, g.size(), mod);
    }
    int lmax = path_length(g, 0, -1);
    for (int i = 0; i < g.size(); i++)
    {
        if (i == 0 && g[i].size() == 2)
        {

            vector<int> ps;
            for (int to : g[i])
            {
                ps.push_back(path_length(g, to, i));
            }
            if (ps[0] == ps[1])
                return mod_pow(2, lmax - *min_element(ps.begin(), ps.end()) + 1, mod);
            int l = lmax - *min_element(ps.begin(), ps.end());
            ll res = (mod_pow(2, l, mod) + mod_pow(2, l - 1, mod)) % mod;
            return res;
        }
        if (g[i].size() > 2)
        {
            int parent = -1;
            for (int to : g[i])
                if (reach_zero(g, to, i))
                {
                    parent = to;
                    break;
                }
            vector<int> ps;
            for (int to : g[i])
            {
                if (to != parent)
                {
                    ps.push_back(path_length(g, to, i));
                }
            }
            if (ps[0] == ps[1])
                return mod_pow(2, lmax - *min_element(ps.begin(), ps.end()) + 1, mod);
            int l = lmax - *min_element(ps.begin(), ps.end());
            ll res = (mod_pow(2, l, mod) + mod_pow(2, l - 1, mod)) % mod;
            return res;
        }
    }
    int a = 1 / 0;
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;
    while (numTests--)
    {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }
        cout << compute(g) << endl;
    }
}