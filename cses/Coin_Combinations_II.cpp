

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vint;
typedef vector<ll> vlong;

#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()

ll mod = 1e9 + 7;

int dp[(int)1e6 + 5];
int main()
{
    int n, x;
    cin >> n >> x;
    vint c(n);
    for (int &i : c)
        cin >> i;
    sort(all(c));
    fill_n(dp, x + 5, 0);
    dp[0] = 1;
    for (int &coin : c)
    {
        for (int j = coin; j <= x; j++)
        {
            dp[j] += dp[j - coin];
            if (dp[j] >= mod)
                dp[j] -= mod;
        }
    }
    cout << dp[x];
    return 0;
}