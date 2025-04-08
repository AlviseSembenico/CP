
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
#include <iterator>

using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "./codeforces/debug.hpp"
#endif

typedef long long int ll;

ll mod = 1e9 + 7;

ll dp[100005];
ll dp2[100005];
ll compute(int a, int b, int k)
{
    ll res = dp2[b] - dp2[a - 1];
    if (res < 0)
        return (res + mod) % mod;
    return res;
}

void init(int k)
{
    dp[0] = 1;
    dp[1] = k == 1 ? 2 : 1;
    for (int i = 2; i < 100005; i++)
    {
        dp[i] = dp[i - 1];
        if (i - k >= 0)
            dp[i] += dp[i - k];
        dp[i] = dp[i] % mod;
    }
}

int main()
{
    fill(begin(dp), end(dp), -1);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int numTests, k;
    cin >> numTests;
    cin >> k;
    init(k);
    ll c = 0;
    for (int i = 0; i < 100005; i++)
    {
        c += dp[i];
        c = c % mod;
        dp2[i] = c;
    }
    while (numTests--)
    {
        int a, b;
        cin >> a >> b;
        cout << compute(a, b, k) << endl;
    }
}