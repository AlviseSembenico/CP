#include <bits/stdc++.h>
using namespace std;

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

vector<int> factor(int n)
{
    vector<int> factors;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            if (i != n / i)
            {
                factors.push_back(n / i);
            }
        }
    }
    sort(factors.begin(), factors.end());
    return factors;
}