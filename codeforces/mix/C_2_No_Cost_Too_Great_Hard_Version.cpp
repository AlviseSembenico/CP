

#include <bits/stdc++.h>

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

#define pb push_back
#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()

const int UPSIZE = 2 * 1e5 + 5;

vector<bool> isPrime(UPSIZE, true);
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
vector<vint> pfac(UPSIZE);
vint factorize(int i)
{
    return pfac[i];
}
vint factorize2(int i)
{
    vint res;
    if (isPrime[i])
    {
        res = {i};
        return res;
    }
    for (int p : primes)
    {
        if (i % p == 0)
        {
            res.push_back(p);
            while (i % p == 0)
                i /= p;
        }
        if (p * p > i)
            break;
    }
    if (i > 1)
        res.push_back(i);
    sort(all(res));
    return res;
}

vector<bool> seen(UPSIZE, false);

int comp(vint &v, vlong &cost)
{
    unordered_map<int, int> m;
    vector<pil> p;
    for (int i = 0; i < v.size(); i++)
        p.push_back(make_pair(cost[i], v[i]));
    sort(all(p));
    vint ff;
    for (int i : v)
    {
        vint fac = factorize(i);
        for (int pr : fac)
        {
            if (m[pr] >= 1)
                return 0;
            m[pr]++;
            ff.push_back(pr);
        }
    }
    ll res = LONG_LONG_MAX;
    // sort(all(ff));
    // check if you can just raise 1 or 2 to a even number

    int r = 0;
    int cc = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int val = p[i].second;
        int ci = p[i].first;
        if (val % 2 == 0)
            continue;
        else
        {
            r += ci;
            cc++;
        }
        if (cc == 2 - m[2])
        {
            res = r;
            break;
        }
    }
    // in this case we only have 1s
    if (ff.size() == 0)
    {
        return p[0].first + p[1].first;
    }

    for (int i = 0; i < v.size(); i++)
    {
        int val = p[i].second;
        int ci = p[i].first;
        vint f2 = factorize(val + 1);
        for (int f : f2)
        {
            if (m[f] >= 1)
            {
                res = min(res, (ll)ci);
                break;
            }
        }
    }

    int minn = p[0].first;
    for (int i = 0; i < 1; i++)
    {
        int val = p[i].second;
        int ci = p[i].first;
        if (ci > minn)
            break;
        for (ll f : ff)
        {
            if (val % f == 0)
                continue;

            ll t = (floor((double)val / f) + 1) * f - val;
            res = min(res, t * ci);
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    primes = getPrimes(UPSIZE);
#ifdef CINPUT
    freopen("input.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    int i = 0;
    for (int i = 2; i < UPSIZE; i++)
    {
        pfac[i] = factorize2(i);
    }
    while (t--)
    {
        int n;
        cin >> n;
        vint a(n);
        loop0(n)
                cin >>
            a[i];

        vlong cost(n);
        loop0(n)
                cin >>
            cost[i];
        // if (++i == 54)
        // {
        //     for (int i : a)
        //         cout << i << "0";
        // cout << "7";
        // for (int i : cost)
        //     cout
        //         << i << "0";
        // }
        cout << comp(a, cost) << endl;
    }
}