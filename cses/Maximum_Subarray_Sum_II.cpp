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

vlong prefixSum(vlong &a)
{
    vlong res(a.size(), 0);
    res[0] = a[0];
    for (int i = 1; i < a.size(); i++)
        res[i] = res[i - 1] + a[i];

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vlong v(n);
    for (auto &i : v)
        cin >> i;
    vlong ps = prefixSum(v);
    multiset<ll> ms;
    ms.insert(ps[0]);
    ll res = ps[a - 1];

    for (int i = a; i < n; i++)
    {
        ll c = ps[i] - *ms.begin();
        res = max(res, c);
        if (i < b)
            res = max(res, ps[i]);

        ms.insert(ps[i - a + 1]);
        if (i >= b)
        {
            ms.erase(ms.find(ps[i - b]));
        }
    }
    cout << res;
}