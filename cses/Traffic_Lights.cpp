

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, n;
    cin >> x >> n;
    multiset<int> ss;
    map<int, int> m2;
    ss.insert(x);
    m2[0] = x;
    loop0(n)
    {
        int j;
        cin >> j;
        auto p = --m2.upper_bound(j);
        int id = (*p).first;
        int ps = m2[id];
        m2[id] = j - id;
        m2[j] = id + ps - j;
        ss.erase(ss.find(ps));
        ss.insert(j - id);
        ss.insert(id + ps - j);
        cout << *(--ss.end()) << ' ';
    }
}