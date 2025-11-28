
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <climits>
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

ll cost(vint &a, vint &c, int i, int v)
{
}

ll comp(vint &a, vint &c)
{
    if (a.size() == 1)
        return 0;
    unordered_set<int> ss;
    for (int i : a)
        ss.insert(i);
    vint vals(all(ss));
    unordered_map<int, int> mp;
    sort(all(vals));
    vlong prev(a.size() + 5);
    for (int i = 0; i < vals.size(); i++)
    {
        mp[vals[i]] = i;
    }
    for (int &i : a)
    {
        i = mp[i];
    }
    for (int i = 0; i < a.size() + 1; i++)
    {

        if (i < a[0])
            prev[i] = c[0];
        else
            prev[i] = 0;
    }
    for (int i = 1; i < a.size(); i++)
    {
        vlong next(a.size() + 1);
        ll c1 = c[i];
        ll a1 = a[i];
        for (int v = 0; v <= a.size(); v++)
        {
            if (v < a1)
                next[v] = prev[v] + c1;
            if (v == a1)
                next[v] = prev[v];
            if (v > a1)
                next[v] = min(prev[a1], prev[v] + c1);
        }
        prev = next;
    }
    return *min_element(all(prev));
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
        int n;
        cin >> n;
        vint a(n);
        vint c(n);
        loop0(n)
                cin >>
            a[i];
        loop0(n)
                cin >>
            c[i];
        cout << comp(a, c) << endl;
    }
}