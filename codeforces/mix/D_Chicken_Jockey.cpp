
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

// ll dp[(int)1e5 * 2 + 1];
ll comp(vlong &v)
{
    ll a = 0;
    ll b = v[0];
    ll c;
    for (int i = 2; i <= v.size(); i++)
    {
        ll x = v[i - 1];
        c = min(b + x - 1, a + v[i - 2] + max(0LL, x - (i - 1)));
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vlong v(n);
        for (auto &i : v)
            cin >> i;
        cout << comp(v) << endl;
    }
}