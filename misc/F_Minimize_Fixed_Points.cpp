
#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "./codeforces/debug.hpp"
#endif

typedef long long int ll;
typedef vector<int> vint;
typedef vector<ll> vlong;

#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))

vector<int> getPrimes(int n)
{
    vector<bool> isPrime(n + 1, true);
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

vector<int> factor(int n, int N)
{
    vector<int> factors;
    int last_factor = -1;

    for (int i = 0; primes[i] * 2 <= n; i++)
    {

        if (n % primes[i] == 0)
        {
            factors.push_back(primes[i]);
        }
    }
    if (factors.empty())
        return {n};
    // if (n * 2 <= N)
    //     factors.push_back(n);
    return factors;
}

vector<int> build(int n)
{
    vector<vint> d(n + 5);

    for (int i = 2; i <= n; i++)
    {
        vector<int> factors = factor(i, n);
        for (int f : factors)
            d[f].push_back(i);
    }
    vector<pair<int, vector<int>>> m;
    for (int i = 2; i <= n; i++)
        m.push_back(make_pair(i, d[i]));

    sort(m.begin(), m.end(), [](const auto &a, const auto &b)
         { return a.second.size() < b.second.size(); });

    vint res(n + 5, 0);
    res[1] = 1;
    for (auto p : m)
    {
        if (p.second.empty())
            continue;
        vint good;
        for (int i : p.second)
            if (res[i] == 0)
                good.push_back(i);
        sort(good.begin(), good.end());
        for (int i = 0; i + 1 < good.size(); i++)
        {
            res[good[i]] = good[i + 1];
        }
        res[good.back()] = good[0];
    }
    return res;
}

int main()
{
    primes = getPrimes(1e5 + 5);
    // build(100000);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vint res = build(n);
        for (int i = 1; i <= n; i++)
            cout << res[i] << ' ';
        cout << endl;
    }
}