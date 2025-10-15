
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

bool test(vint c, vint ref)
{
    int t = accumulate(all(c), 0);
    int left = 0;
    for (int i = 0; i < c.size(); i++)
    {
        t -= c[i];
        int curr = t + left + 1;
        if (curr != ref[i])
            return false;
        if (c[i] == 0)
            left++;
    }
    return true;
}

ll comp(vint &v)
{

    vint c(v.size() + 5, 0);
    for (int i : v)
        c[i]++;
    int n = v.size();
    if (n % 2 == 1 && c[(n + 1) / 2] == n)
        return 2;

    vint c1 = {0};
    vint c2 = {1};
    int prev = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == prev)
        {
            c1.push_back(1 - c1.back());
            c2.push_back(1 - c2.back());
        }
        else
        {
            c1.push_back(c1.back());
            c2.push_back(c2.back());
        }
        prev = v[i];
    }
    if (test(c1, v) || test(c2, v))
        return 1;
    return 0;
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
        vint v(n);
        loop0(n)
                cin >>
            v[i];
        cout << comp(v) << endl;
    }
}