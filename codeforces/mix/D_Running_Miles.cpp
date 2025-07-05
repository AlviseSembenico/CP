
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

#define all(x) x.begin(), x.end()

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

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// we can now use it with unordered_map, unordered_set, etc.
// unordered_map<int, int, custom_hash> m;

vlong dp1;
vlong dp2;
vlong dp3;

ll comp(vlong &l)
{
    if (l.size() == 3)
        return reduce(all(l), 0LL) - 2;
    vlong mleft = {l[0] - 1};
    ll m = l[0] - 1;
    for (int i = 1; i < l.size() - 1; i++)
    {
        m = max(--m, l[i] - 1);
        mleft.push_back(m);
    }

    vlong mright(l.size(), 0);
    mright[l.size() - 2] = l[l.size() - 1] - 1;

    m = l[l.size() - 1] - 1;
    for (int i = l.size() - 2; i >= 1; i--)
    {
        m = max(--m, (ll)(l[i] - 1));
        mright[i - 1] = m;
    }
    ll res = 0;
    for (int i = 1; i < l.size() - 1; i++)
        res = max(res, mleft[i - 1] + mright[i] + l[i]);
    // cout << "mleft: " << mleft << "\n";
    // cout << "mright: " << mright << "\n";
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;
    while (numTests--)
    {
        int size;
        dp1.assign(size + 1, 0LL);
        dp2.assign(size + 1, 0LL);
        dp3.assign(size + 1, 0LL);

        cin >> size;
        cin.ignore();
        vlong arr(size);

        for (ll i = 0; i < size; i++)
            cin >> arr[i];
        cout << comp(arr) << "\n";
    }
}