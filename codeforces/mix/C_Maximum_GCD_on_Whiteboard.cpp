
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

bool reach(vint &v, int k, int t)
{
    for (int n : v)
    {
        if (n % t == 0)
            continue;
        if (n >= 4 * t)
            continue;
        k--;
        if (k < 0)
            return false;
    }
    return true;
}

int comp(vint &v, int k)
{
    sort(all(v));
    vint cc(5 * v.size(), 0);
    for (int i : v)
        cc[i]++;

    for (int g = v.size(); g >= 1; g--)
    {
        int c = 0;
        c += cc[2 * g];
        c += cc[3 * g];
        c += cc[g];
        c += v.end() - lower_bound(all(v), 4 * g);
        if (c + k >= v.size())
            return g;
    }
    return 1;
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
        vint v(n);
        loop0(n)
        {
            cin >> v[i];
        }
        cout << comp(v, k) << endl;
    }
}