#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
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
#define pb push_back
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

ll triple(ll a, ll b, ll c)
{
    vlong v = {a, b, c};
    sort(all(v));
    return -v[0] + v[2];
}

ll compute(deque<ll> &a)
{
    int n = a.size();
    if (n == 3)
        return triple(a[0], a[1], a[2]);
    vlong dp(n, LONG_LONG_MAX);

    dp[1] = abs(a[0] - a[1]);
    dp[2] = triple(a[0], a[1], a[2]);
    for (int i = 3; i < n; i++)
    {
        dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 1]));
        if (i >= 4)
            dp[i] = min(dp[i], dp[i - 3] + triple(a[i], a[i - 1], a[i - 2]));
    }
    return dp.back();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef CINPUT
    freopen("input.txt", "r", stdin);
#endif
    int t;
    cin >> t;

    while (t--)
    {
        ii++;

        int n;
        cin >> n;
        deque<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        ll res = compute(a);
        for (int i = 0; i < 3; i++)
        {

            ll b = a.back();
            a.pop_back();
            a.push_front(b);
            res = min(res, compute(a));
        }
        for (int i = 0; i < 3; i++)
        {

            ll b = a.front();
            a.pop_front();
            a.push_back(b);
        }
        for (int i = 0; i < 3; i++)
        {

            ll b = a.front();
            a.pop_front();
            a.push_back(b);
            res = min(res, compute(a));
        }

        cout << res << endl;
    }
    return 0;
}
