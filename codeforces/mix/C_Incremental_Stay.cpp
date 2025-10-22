
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
        vint v(2 * n);
        loop0(2 * n) cin >> v[i];
        vlong cs1 = {0};
        vlong cs0 = {0};
        for (int i = 1; i < 2 * n - 1; i += 2)
        {
            cs1.push_back(cs1.back() + v[i + 1] - v[i]);
        }
        for (int i = 0; i < 2 * n - 1; i += 2)
        {
            cs0.push_back(cs0.back() + v[i + 1] - v[i]);
        }
        cout << cs0.back() << ' ';
        ll totr = 0;
        ll totl = 0;
        for (int i = 1; i < n; i++)
        {
            totr += v[v.size() - i];
            totl += v[i - 1];
            ll r = totr - totl;
            if (i % 2)
            {
                r += cs1[cs1.size() - 1 - i / 2] - cs1[i / 2];
            }
            else
            {
                r += cs0[cs0.size() - 1 - i / 2] - cs0[i / 2];
            }
            cout << r << ' ';
        }
        cout << endl;
    }
}