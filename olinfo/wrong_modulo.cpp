
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

vector<bool> isPrime(SIZE + 5, true);
vector<int> getPrimes(int n)
{
    isPrime[0] = isPrime[1] = false; //
    for (int i = 2; i * i <= n; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}

vint primes;
unordered_map<int, int> factorize(int i)
{
    unordered_map<int, int> res;
    for (int p : primes)
    {
        if (i % p == 0)
        {
            while (i % p == 0)
            {
                res[p]++;
                i /= p;
            }
        }
        if (p * p > i)
            break;
    }
    if (i > 1)
        res[i]++;
    return res;
}

ll func(int N, int a)
{
    ll res = 0;
    for (int x = 1; x <= N; x++)
    {
        if (a == 1)
            return N * N;
        auto v = factorize(x);
        ll cnt = 1;
        for (auto [p, e] : v)
            cnt *= e + 1;
        res += cnt;
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
    primes = getPrimes(SIZE);
    int t;
    cin >> t;
    while (t--)
    {
        int N, a;
        cin >> N >> a;
        cout << func(N, a) << endl;
    }
}