#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vint;

vector<bool> isPrime(n + 1, true);
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

vint factorize(int i)
{
    vint res;
    if (isPrime[i])
    {
        res = {i};
        return res;
    }
    // Use primes computed from the above function
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