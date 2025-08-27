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
        vlong v(n);
        for (ll &i : v)
            cin >> i;
        ll res = 0;
        if (n % 2 == 0)
            v.push_back(0);
        for (int i = 1; i < n; i++)
        {
            if (i % 2 == 1)
            {
                if (v[i - 1] + v[i + 1] > v[i])
                {
                    res += max(0LL, v[i - 1] - v[i]);

                    res += max(0LL, v[i + 1] - v[i]);
                    v[i + 1] -= max(0LL, v[i + 1] - v[i]);
                    v[i - 1] -= max(0LL, v[i - 1] - v[i]);
                    ll nd = max(0LL, (v[i - 1] + v[i + 1]) - v[i]);
                    res += nd;
                    // ll nd2 = nd - min((ll)v[i + 1], nd);
                    v[i + 1] -= min((ll)v[i + 1], nd);
                }
            }
        }
        cout << res << endl;
    }
}