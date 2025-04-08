
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

typedef long long int ll;

ll check(int n, int m, int x)
{
    ll c = 1;
    for (int i = 1; i <= min(n, x); i++)
    {
        c += min((x - 1) / i, m);
    }
    // cout << x << ' ' << c << endl;
    return c;
}

ll comp(int n, int m, int k)
{
    ll i = 0;
    ll j = n * m;
    while (i < j - 1)
    {
        int mid = (i + j) / 2;
        if (check(n, m, mid) > k)
            j = mid;
        else
            i = mid;
    }
    if (check(n, m, i) < k)
        return j;
    return i;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    cout << comp(n, m, k);
}