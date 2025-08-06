#include <bits/stdc++.h>
using namespace std;

struct SegmentTree
{
    int n;
    vector<int> tree;

    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void build(vector<int> &arr, int node, int l, int r)
    {
        if (l == r)
        {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, node * 2, l, mid);
        build(arr, node * 2 + 1, mid + 1, r);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int idx, int val) { update(1, 0, n - 1, idx, val); }
    void update(int node, int l, int r, int idx, int val)
    {
        if (l == r)
        {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int ql, int qr) { return query(1, 0, n - 1, ql, qr); }
    int query(int node, int l, int r, int ql, int qr)
    {
        if (qr < l || ql > r)
            return INT_MIN;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        return max(query(node * 2, l, mid, ql, qr),
                   query(node * 2 + 1, mid + 1, r, ql, qr));
    }
};

int main()
{
    vector<int> arr = {1, 5, 2, 4, 3};
    SegmentTree st(arr);
    cout << st.query(1, 3) << "\n"; // 5
    st.update(2, 6);
    cout << st.query(1, 3) << "\n"; // 6
}
