

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
// we can now use it with unordered_map, unordered_set, etc.
unordered_map<int, int, custom_hash> m;

vector<int> digits_from_math(int n)
{
    if (n == 0)
        return {0};
    vector<int> d;
    while (n > 0)
    {
        d.push_back(n % 10);
        n /= 10;
    }
    reverse(d.begin(), d.end());
    return d;
}

int dp[(int)1e6 + 5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    fill_n(dp, n + 5, INT_MAX / 2);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int n = i;
        int r = INT_MAX;
        while (n > 0)
        {
            int d = n % 10;
            n /= 10;
            r = min(r, dp[i - d] + 1);
        }
        dp[i] = r;
    }
    cout << dp[n];
    return 0;
}