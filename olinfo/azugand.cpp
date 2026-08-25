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

const int DIM = 2005;
int dist[25][25];
template <size_t R, size_t C>
void floydwarshall(const vector<vector<int>> &g, int (&d)[R][C])
{
    int n = g.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            d[i][j] = (i == j) ? 0 : 1e9;
        }
        for (int j : g[i])
        {
            d[i][j] = 1;
        }
    }

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int comp(int x, int y)
{
    if (x & y)
        return 1;
    int res = 1e9;
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
        {
            if (((1 << i) & x) && ((1 << j) & y))
                res = min(res, 1 + dist[i][j]);
        }
    if (res == 1e9)
        return -1;
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef CINPUT
    freopen("input.txt", "r", stdin);
#endif
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vint> g(22);
    for (int x1 : v)
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 20; j++)
            {

                if (((1 << i) & x1) && ((1 << j) & x1))
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
    floydwarshall(g, dist);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << comp(v[x - 1], v[y - 1]) << endl;
    }
}
