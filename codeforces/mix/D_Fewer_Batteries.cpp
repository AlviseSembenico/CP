#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0

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

ll visited[(int)2e5 + 5];
ll comp(vector<vector<pair<int, ll>>> &g, vector<ll> &bs, int n)
{
    priority_queue<
        tuple<ll, ll, int>,
        vector<tuple<ll, ll, int>>,
        greater<tuple<ll, ll, int>>>
        pq;
    pq.push(make_tuple(0, 0, 1));
    fill(visited, visited + g.size() + 5, -1);
    while (!pq.empty())
    {
        auto [cost, batt, node] = pq.top();
        // cout << cost << " " << batt << " " << node << " " << visited[node] << endl;
        if (node == n)
            return cost;
        pq.pop();

        if (visited[node] >= batt)
            continue;
        visited[node] = batt;
        for (auto &[next, weight] : g[node])
        {
            // cout << "Next: " << next << " Weight: " << weight << " Bs: " << bs[node] << endl;
            if (batt + bs[node] >= weight)
            {
                pq.push(make_tuple(max(cost, weight), batt + bs[node], next));
            }
        }
    }
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
        int n, m;
        cin >> n >> m;
        vector<ll> bs(n + 5);
        vector<vector<pair<int, ll>>> g(n + 5);

        for (int i = 1; i <= n; i++)
            cin >> bs[i];
        for (int i = 0; i < m; i++)
        {
            int f, t;
            ll w;
            cin >> f >> t >> w;
            g[f].push_back(make_pair(t, w));
        }
        // for (auto [t, w] : g[2])
        // cout << t << " " << w << endl;
        cout << comp(g, bs, n) << endl;
    }
}