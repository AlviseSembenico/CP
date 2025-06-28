#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "./codeforces/debug.hpp"
#endif

typedef long long int ll;
typedef vector<int> vint;
typedef vector<ll> vlong;

#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(all(v), x) != v.end())

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

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// function to return a nxm grid of custom types, custom values
template <typename T>
vector<vector<T>> createGrid(int n, int m, T defaultValue)
{
    return vector<vector<T>>(n, vector<T>(m, defaultValue));
}

// we can now use it with unordered_map, unordered_set, etc.
// unordered_map<int, int, custom_hash> m;

inline vector<vector<int>> readUndirectedGraph()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++)
    {
        int f, t;
        cin >> f >> t;
        f--;
        t--;
        g[f].push_back(t);
        g[t].push_back(f);
    }
    return g;
}

void minDistance(int start, int end, vector<vector<int>> &g)
{
    vector<bool>
        seen(g.size(), false);
    seen[start] = true;
    vint q = {start};
    int c = 0;
    unordered_map<int, int> adj;
    bool found = false;
    while (q.size() > 0)
    {
        vint nq;
        for (int i : q)
        {
            if (i == end)
            {
                found = true;
                break;
            }
            for (int to : g[i])
                if (!seen[to])
                {
                    seen[to] = true;
                    nq.push_back(to);
                    adj[to] = i;
                }
        }
        q.swap(nq);
        c++;
    }
    if (!found)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    int p = end;
    vint res = {end};
    while (p != start)
    {
        p = adj[p];
        res.push_back(p);
    }
    reverse(all(res));
    cout << res.size() << endl;
    for (int i : res)
        cout << i + 1 << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vint> g = readUndirectedGraph();
    minDistance(0, g.size() - 1, g);
    return 0;
}