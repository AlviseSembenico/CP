

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
// unordered_map<int, int, custom_hash> m;

bool complete(vint &g, int s, int n)
{
    for (int p = 0; p < n; p++)
    {
        if ((s & (1 << p)) == 0)
            continue;
        if (((g[p] | (1 << p)) & s) != s)
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vint g(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int f, t;
        cin >> f >> t;
        f--;
        t--;
        g[f] |= (1 << t);
        g[t] |= (1 << f);
    }
    vint dp(1 << n, INT_MAX);
    for (int s = 1; s < (1 << n); s++)
    {
        if (complete(g, s, n))
        {
            dp[s] = 1;
        }
    }
    // cout << dp << endl;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int submask = mask; submask != 0; submask = (submask - 1) & mask)
        {
            int subset = mask ^ submask;
            if (dp[subset] != INT_MAX && dp[submask] != INT_MAX)
                dp[mask] = min(dp[mask], dp[subset] + dp[submask]);
        }
    }
    cout << dp[(1 << n) - 1];
    return 0;
}