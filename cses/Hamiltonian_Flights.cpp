

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
ll mod = (ll)1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vint> g(n + 2);
    loop0(m)
    {
        int f, t;
        cin >> f >> t;
        f--;
        t--;
        g[t].push_back(f);
    }

    auto dp = createGrid(1 << n, n, 0LL);
    dp[1][0] = 1;
    int SS = 1 << n;

    for (int s = 2; s < SS; s++)
    {
        if ((s & 1) == 0)
            continue;
        if ((s & (1 << (n - 1))) && (s != SS - 1))
            continue;
        for (int end = 1; end < n; end++)
        {
            if ((s & (1 << end)) == 0)
                continue;
            int p = s - (1 << end);
            for (int from : g[end])
            {
                if ((s & (1 << from)) == 0)
                    continue;
                dp[s][end] += dp[p][from];
                dp[s][end] %= mod;
            }
        }
    }
    cout << dp[SS - 1][n - 1];
    return 0;
}