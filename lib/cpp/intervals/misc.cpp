#include <algorithm>
#include <vector>
using namespace std;

typedef long long int ll;

bool intersect(int l1, int r1, int l2, int r2)
{
    return max(l1, l2) <= min(r1, r2);
}

class SegTree
{
    void build(vector<ll> &a, ll v, ll tl, ll tr)
    {
        if (tl == tr)
        {
            tree[v] = a[tl];
        }
        else
        {
            ll tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    ll _sum(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return 0LL;
        if (l == tl && r == tr)
        {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return _sum(v * 2, tl, tm, l, min(r, tm)) + _sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

public:
    vector<ll> tree;
    int size;

    SegTree(vector<ll> s)
    {
        tree.reserve(4 * s.size());
        build(s, 1, 0, s.size() - 1);
        size = s.size();
    }

    ll sum(int l, int r)
    {
        return _sum(1, 0, size - 1, l, r);
    }
};