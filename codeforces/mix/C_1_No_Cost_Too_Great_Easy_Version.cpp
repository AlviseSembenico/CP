
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

vint factorize(int i)
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
    return res;
}
vector<bool> seen(UPSIZE, false);
int comp(vint &v)
{
    int n = *max_element(all(v));
    fill_n(seen.begin(), n + 5, false);
    for (int i : v)
    {
        vint fac = factorize(i);
        for (int pr : fac)
            if (seen[pr])
                return 0;
            else
                seen[pr] = true;
    }
    for (int i : v)
    {
        vint fac = factorize(i + 1);
        for (int pr : fac)
            if (seen[pr])
                return 1;
    }

    return 2;
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
    int i;
    while (t--)
    {
        int n;
        cin >> n;
        vint a(n);
        loop0(n)
                cin >>
            a[i];

        int p;
        loop0(n)
                cin >>
            p;

        cout << comp(a) << endl;
    }
}