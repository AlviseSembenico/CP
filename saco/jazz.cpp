
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
template <typename T>
vector<vector<T>> createGrid(int n, int m, T defaultValue)
{
    return vector<vector<T>>(n, vector<T>(m, defaultValue));
}

vector<vint> dp;
bool isvalid(int i, int j, string &s)
{
    vector<char> stack;
    for (char c : s)
    {
        stack.push_back(c);
        while (stack.size() > 1 && stack.back() == stack[stack.size() - 2])
        {
            stack.pop_back();
            stack.pop_back();
        }
    }
    return stack.empty();
}

int f(int i, int j, string &s)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i > j)
        return 0;
    if (i == j)
        return 1;
    if (s[i] == s[j])
        return dp[i][j] = f(i + 1, j - 1, s);

    if (isvalid(i, j, s))
        return dp[i][j] = 0;
    int r = INT_MAX;
    for (int x = i; x < j; x++)
    {
        r = min(f(i, x, s) + f(x + 1, j, s), r);
    }
    dp[i][j] = r;
    return r;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    dp = createGrid(s.size(), s.size(), -1);
    cout << f(0, s.size() - 1, s);
    // cout << f(2, 4, s);
    return 0;
}