
#include <bits/stdc++.h>
#include <unordered_map>

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
using Grid2D = vector<vector<int>>;
using Grid3D = vector<Grid2D>;

auto make_3d(int d1, int d2, int d3, int val = 0)
{
    return Grid3D(d1, vector<vector<int>>(d2, vector<int>(d3, val)));
}
auto make_2d(int d1, int d2, int val = 0)
{
    return Grid2D(d1, vector<int>(d2, val));
}

#define pb push_back
#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))
const int SIZE = 1e6;

ll func(ll N, int a)
{
    if (a == 1)
        return 1LL * N * N;
    ll res = 0;
    int x = 1;
    while (x <= N)
    {
        ll v = floor((double)N / x);
        int nx = N / v + 1;
        res += (nx - x) * v;
        x = nx;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef CINPUT
    freopen("input.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        ll N, a;
        cin >> N >> a;
        cout << func(N, a) << endl;
    }
}