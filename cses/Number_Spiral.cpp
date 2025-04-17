#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
#include <climits>
#include <algorithm>

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

ll comp(ll x, ll y)
{
    ll d = max(x, y) - 1;
    ll res = d * d;
    if (!(d % 2))
    {
        res += y;
        if (x == d + 1)
            return res;
        res += (d + 1 - x);
        return res;
    }
    res += x;
    if (y == d + 1)
        return res;
    res += (d + 1 - y);
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;
    while (numTests--)
    {
        ll x, y;
        cin >> x >> y;
        cin.ignore();

        cout << comp(x, y) << endl;
    }
}