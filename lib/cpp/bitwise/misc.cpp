
#include <bits/stdc++.h>
using namespace std;

void loopsubset(int n)
{
    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int submask = mask; submask != 0; submask = (submask - 1) & mask)
        {
            int subset = mask ^ submask;
        }
    }
}

// how to read a graph
void readGraph()
{
    int n, m;
    cin >> n >> m;
    vector<int> g(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int f, t;
        cin >> f >> t;
        f--;
        t--;
        g[f] |= (1 << t);
        g[t] |= (1 << f);
    }
}