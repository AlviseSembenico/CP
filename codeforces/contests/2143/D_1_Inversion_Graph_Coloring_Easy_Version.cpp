
#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "./codeforces/debug.hpp"
#endif

#ifndef ONLINE_JUDGE
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}
#else
// If not debugging, define deb as empty
#define deb(...)
#endif
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<int> vint;
typedef vector<ll> vlong;

#define pb push_back
#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))

ll ways[2][305][305] = {};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    ll mod = 1e9 + 7;
    while (t--)
    {
        memset(ways, 0, sizeof(ways));
        int n;
        cin >> n;
        vint v(n);
        for (auto &i : v)
            cin >> i;

        // i, max, second max
        ways[0][1][0] = 1;
        int cc = 0;
        for (int i = 0; i < n; i++)
        {
            cc ^= 1;
            int val = v[i];
            for (int j = 0; j <= n; j++)
                for (int q = 0; q <= n; q++)
                    ways[cc][j][q] = ways[cc ^ 1][j][q];
            for (int j = 0; j <= n; j++)
                for (int q = 0; q <= n; q++)
                {
                    if (val >= j)
                    {
                        ways[cc][val][q] += ways[cc ^ 1][j][q];
                        ways[cc][val][q] %= mod;
                    }
                    else if (val >= q)
                    {
                        ways[cc][j][val] += ways[cc ^ 1][j][q];
                        ways[cc][j][val] %= mod;
                    }
                }
        }
        long long sum = 0;
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
            {
                sum += ways[cc][j][k];
                sum %= mod;
            }
        cout << sum << endl;
    }
}