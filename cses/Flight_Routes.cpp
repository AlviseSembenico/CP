
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
typedef long long int ll;
typedef vector<int> vint;
typedef vector<ll> vlong;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;

#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))

priority_queue<ll> best[(int)1e5 + 5];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pil>> g(n + 1);
    while (m--)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
    }

    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    pq.push({0, 1});
    while (!pq.empty())
    {
        const auto [cdist, node] = pq.top();

        pq.pop();

        for (const pair<int, int> &i : g[node])
        {
            ll val = cdist + i.second;
            if (best[i.first].size() < k)
            {
                pq.push({val, i.first});
                best[i.first].push(val);
            }
            else if (val < best[i.first].top())
            {
                best[i.first].pop();
                pq.push({val, i.first});
                best[i.first].push(val);
            }
        }
    }
    vlong res;
    while (best[n].size())
    {
        res.push_back(best[n].top());
        best[n].pop();
    }
    reverse(all(res));
    for (ll i : res)
        cout << i << ' ';
}