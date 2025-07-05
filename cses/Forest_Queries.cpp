
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int size, q;
    cin >> size >> q;
    cin.ignore();
    vector<vint> forest(size);
    for (int i = 0; i < size; i++)
    {
        forest[i].resize(size);
        for (int j = 0; j < size; j++)
        {
            char c;
            cin >> c;
            forest[i][j] = c == '*';
        }
    }

    vector<vint> dp(size, vint(size, 0));
    for (int i = 1; i < size; i++)
    {
        forest[0][i] = forest[0][i - 1] + forest[0][i];
        forest[i][0] = forest[i - 1][0] + forest[i][0];
    }
    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            forest[i][j] = forest[i - 1][j] + forest[i][j - 1] - forest[i - 1][j - 1] + forest[i][j];
        }
    }

    for (int i = 0; i < q; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cin.ignore();
        x1--;
        y1--;
        x2--;
        y2--;
        ll res = forest[x2][y2];
        if (x1 > 0)
            res -= forest[x1 - 1][y2];
        if (y1 > 0)
            res -= forest[x2][y1 - 1];
        if (x1 > 0 && y1 > 0)
            res += forest[x1 - 1][y1 - 1];
        // ll res = forest[x2][y2] - forest[x1 - 1][y2] - forest[x2][y1 - 1] + forest[x1 - 1][y1 - 1];
        cout << res << endl;
    }
}