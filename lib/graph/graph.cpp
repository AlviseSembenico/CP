#include <vector>
#include <unordered_map>

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

int main() { return 1; }