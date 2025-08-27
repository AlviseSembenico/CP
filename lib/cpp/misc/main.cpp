#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<int> vint;
typedef vector<ll> vlong;

#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))

vlong prefixSum(vlong &a)
{
    vlong res(a.size(), 0);
    res[0] = a[0];
    for (int i = 1; i < a.size(); i++)
        res[i] = res[i - 1] + a[i];

    return res;
}