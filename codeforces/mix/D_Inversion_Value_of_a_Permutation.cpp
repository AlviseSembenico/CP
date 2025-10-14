
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

bool cos(vint &v, int k, int ld, int n)
{
    if (k < 0)
        return false;
    if (v.size() == n)
        return k == 0;
    if (k == 0)
    {
        for (int i = 0; i < n; i++)
            v.push_back(1);

        return true;
    }
    // consider down
    int nt = k - n * (1 + ld);
    if (nt < 0)
        return false;
    if (cos(v, nt, 0, n - 1))
    {
        v.push_back(-1);
        return true;
    }

    // consider up
    if (cos(v, k, ld + 1, n - 1))
    {
        v.push_back(1);
        return true;
    }
    return false;
}

vint clean(vint &v)
{
    vint r(v.size() + 1, 0);
    int mi = 1;
    int ma = v.size() + 1;
    for (int i = v.size(); i >= 1; i--)
    {
        if (v[i - 1] < 0)
            r[i] = mi++;
        else
            r[i] = ma--;
    }
    r[0] = ma;
    return r;
}

vint comp(int n, int k)
{
    vint res;
    cos(res, k, 0, n - 1);
    if (res.empty())
        return res;

    return clean(res);
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
        int n, k;
        cin >> n >> k;
        vint r = comp(n, k);
        if (r.empty())
            cout << 0;
        else
            for (int i : r)
                cout << i << ' ';
        cout << endl;
    }
}