
#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "./codeforces/debug.hpp"
#endif

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << " ";
    }
    return os;
}

typedef long long int ll;

string comp(ll a, ll b)
{
    if (a < 0 || b < 0)
        return "NO";
    if (a == b)
    {
        if (a % 3 == 0 || a == 0)
            return "YES";
        return "NO";
    }
    if (a < b)
    {
        ll c = a;
        a = b;
        b = c;
    }
    ll c = a - b;

    return comp(a - 2 * c, b - c);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;
    while (numTests--)
    {
        int a, b;
        cin >> a >> b;
        cout << comp(a, b) << endl;
    }
}