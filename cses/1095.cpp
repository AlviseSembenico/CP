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

typedef long long int ll;

ll mod = 1e9 + 7;

ll comp(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (a == 0)
        return 0;
    ll res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
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
        int a, b;
        cin >> a >> b;
        cout << comp(a, b) << endl;
    }
}