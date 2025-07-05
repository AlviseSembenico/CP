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

typedef vector<int> vint;

struct DSU
{
    vint e;
    int bSize = 1;
    int nComp;
    void init(int N)
    {
        e = vint(N, -1);
        nComp = N;
    }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y)
    { // union by size
        x = get(x), y = get(y);
        if (x == y)
            return 0;
        if (e[x] > e[y])
            swap(x, y);
        e[x] += e[y];
        e[y] = x;

        bSize = max(bSize, -e[x]);
        nComp--;
        return 1;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DSU d;
    d.init(n);
    loop0(m)
    {
        int f, t;
        cin >> f >> t;
        d.unite(f - 1, t - 1);
        cout << d.nComp << ' ' << d.bSize << endl;
    }
}
