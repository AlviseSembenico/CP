
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
// #define contains(v, x) (find(begin(v), end(v), x) != end(v))

bool compute(string &s)
{
    if (s.contains("11011") || s == "101")
        return false;
    if (s.starts_with("1011") || s.ends_with("1101"))
        return false;
    // regex re("11(01)+1");
    regex re("(?=(?:^1|11)((01)+)(?:1*$|1))");
    auto begin = sregex_iterator(s.begin(), s.end(), re);
    auto end = sregex_iterator();
    for (auto it = begin; it != end; ++it)
    {
        string block = (*it)[1].str(); // group 1 = (01)+
        int cnt = block.size() / 2;    // number of (01)
        if (cnt % 2 == 1)
            return false;
    }

       return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (compute(s))
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
        i++;
    }
}