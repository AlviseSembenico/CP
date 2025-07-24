#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vint;
typedef vector<ll> vlong;

#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))

long long count_mult(long long x)
{
    return x / 2 + x / 3 + x / 5 + x / 7 - x / 6 - x / 10 - x / 14 - x / 15 - x / 21 - x / 35 + x / 30 + x / 42 + x / 70 + x / 105 - x / 210;
}

ll comp(ll l, ll r)
{
    ll ans = r - l + 1;
    ans -= count_mult(r);
    ans += count_mult(l - 1);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        cout << comp(l, r) << "\n";
    }
}