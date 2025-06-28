#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

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