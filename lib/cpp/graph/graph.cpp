#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

void connected_component(vector<vector<vector<int>>> &graph, int node,
                         unordered_map<int, int> &m, int id)
{
    if (m.contains(node)) // C20 above
        return;
    m[node] = id;
    for (vector<int> edge : graph[node])
        connected_component(graph, edge[0], m, id);
}

void UndirectedGraphWeightsInitializer(int n, vector<vector<int>> &edges,
                                       vector<vector<int>> &query)
{
    vector<vector<vector<int>>> graph(n);
    for (vector<int> edge : edges)
    {
        graph[edge[0]].push_back({edge[1], edge[2]});
        graph[edge[1]].push_back({edge[0], edge[2]});
    }
}

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

bool visited[(int)1e5 + 5];
bool checked[(int)1e5 + 5];
// fill_n(visited, colors.size() + 5, false);
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

vector<vector<int>> graph(N);
void make_graph(vector<vector<int>> &edges, vector<vector<int>> &g)
{
    for (auto e : edges)
    {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[2]);
    }
}