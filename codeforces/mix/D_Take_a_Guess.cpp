
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
unordered_map<int, int, custom_hash> m;

int getsum(int i, int j)
{
    i++;
    j++;
    int an, o;
    cout << "or " << i << " " << j << endl
         << flush;
    cin >> o;
    cout << "and " << i << " " << j << endl
         << flush;
    cin >> an;
    int x = o & (~an);

    return 2 * an + x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k;
    cin >> t >> k;
    int x1 = getsum(0, 1);
    int x2 = getsum(1, 2);
    int x3 = getsum(0, 2);

    int b = (x2 - x3 + x1) / 2;
    int a = x1 - b;
    int c = x2 - b;
    vector<int> v(t);
    v[0] = a;
    v[1] = b;
    v[2] = c;
    for (int i = 3; i < t; i++)
    {
        int x = getsum(0, i);
        v[i] = x - a;
    }
    sort(all(v));
    cout << "finish " << v[k - 1] << endl
         << flush;
    return 0;
}