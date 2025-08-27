
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
#define contains(v, x) (find(begin(v), end(v), x) != end(v))

inline void reduce(vint &gr, vint &par, vint &size, int u)
{
    int gu = u;
    vint seen;

    while (par[gu] != -1)
    {
        seen.push_back(gu);
        gu = par[gu];
    }
    for (int g : seen)
        par[g] = gu;
    gr[u] = gu;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vint gr(n);
    vint size(n, 0);
    loop0(n)
        gr[i] = i;

    vint par(n, -1);
    loop0(q)
    {
        int t, u, v;
        cin >> t >> u >> v;
        reduce(gr, par, size, u);
        reduce(gr, par, size, v);
        if (t == 0)
        {
            if (gr[u] == gr[v])
                continue;
            if (size[gr[u]] > size[gr[v]])
            {
                int tmp = u;
                u = v;
                v = tmp;
            }
            size[gr[u]] += size[gr[v]];
            int gu = gr[u];
            par[gu] = gr[v];
            gr[u] = gr[v];
        }
        else
        {
            if (gr[u] == gr[v])
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}