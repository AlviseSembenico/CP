

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

// function to return a nxm grid of custom types, custom values
template <typename T>
vector<vector<T>> createGrid(int n, int m, T defaultValue)
{
    return vector<vector<T>>(n, vector<T>(m, defaultValue));
}

// we can now use it with unordered_map, unordered_set, etc.

int find_lis(const vector<int> &a)
{
    vector<int> dp;
    for (int i : a)
    {
        int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
        if (pos == dp.size())
        {
            // we can have a new, longer increasing subsequence!
            dp.push_back(i);
        }
        else
        {
            // oh ok, at least we can make the ending element smaller
            dp[pos] = i;
        }
    }
    return dp.size();
}
int main()
{
    int n;
    cin >> n;
    vint a(n);
    loop0(n) cin >> a[i];
    cout << find_lis(a);
}