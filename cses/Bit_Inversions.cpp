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
typedef vector<int> vint;
typedef vector<ll> vlong;

#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))

void update(set<int> &dif, multiset<int> &ret, int x, int size)
{
    if (x == 0 || x == size)
        return;
    if (dif.find(x) != dif.end())
    {
        auto it = dif.find(x);
        auto a = *prev(it);
        auto b = *next(it);

        ret.erase(ret.find(*it - a));
        ret.erase(ret.find(b - *it));
        ret.insert(b - a);
        dif.erase(it);
    }
    else
    {
        // insert x int dif
        auto it = dif.insert(x).first;
        auto a = *prev(it);
        int b = *next(it);
        ret.erase(ret.find(b - a));
        ret.insert(x - a);
        ret.insert(b - x);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n;
    cin >> n;
    multiset<int> ret;
    set<int> dif;
    dif.insert(0);
    dif.insert(s.size());
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            dif.insert(i + 1);
        }
    }
    for (auto it = dif.begin(); next(it) != dif.end(); it++)
    {
        ret.insert(*next(it) - *it);
    }
    loop0(n)
    {
        int j;
        cin >> j;

        update(dif, ret, j - 1, s.size());
        update(dif, ret, j, s.size());
        cout << *ret.rbegin() << ' ';
    }
}