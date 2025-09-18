#include "bits/stdc++.h"

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

#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))

int main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vint v(n);
        for (auto &i : v)
            cin >> i;
        unordered_map<int, vint> m;
        for (int i = 0; i < n; i++)
        {
            int val = v[i];
            m[val].push_back(i);
        }
        vint dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            int val = v[i];
            if (i > 0)
                dp[i] = dp[i - 1];
            if (val == 1)
            {
                dp[i]++;
                continue;
            }
            int vv = v[i];
            int ind = lower_bound(all(m[val]), i) - m[val].begin();
            if (ind < val - 1)
                continue;
            int prev;
            if (dp[m[val][ind - val + 1]] - 1 < 0)
                prev = 0;
            else
                prev = dp[m[val][ind - val + 1] - 1];
            dp[i] = max(dp[i], prev + val);
        }

        cout << *max_element(all(dp)) << endl;
    }
}