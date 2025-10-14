
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

bool compute(ll n)
{

    for (int i = log2(n) + 1; i <= 63; i++)
    {
        bool good = true;
        for (int p = 0; p <= i / 2; p++)
        {
            int ii = i - p - 1;
            if (ii == p && (n & (1LL << p)))
            {
                good = false;
                break;
            }
            int bl = (n & (1LL << p)) > 0;
            int br = (n & (1LL << (ii))) > 0;
            if (bl != br)
            {
                good = false;
                break;
            }
        }
        if (good)
            return true;
    }
    return false;
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
    int i = 1;
    bool cond = false;
    while (t--)
    {
        ll n;
        cin >> n;
        // if (i == 1 && n == 816080157)
        //     cond = true;
        // if (i++ == 1110 && cond)
        //     cout << n << endl;

        if (compute(n))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}