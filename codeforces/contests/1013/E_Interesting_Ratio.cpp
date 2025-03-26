
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <numeric>
using namespace std;

typedef long long ll;
vector<ll> primes;
ll aim = 1e7;
void getFirstNPrimes()
{

    vector<bool> isPrime(aim + 1, true);
    // bool isPrime[aim] = {true};
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= (ll)1e7 + 5; ++i)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j <= aim; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (ll i = 2; i <= aim; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
}

ll comp(ll n)
{
    ll res = 0;
    for (int prime : primes)
    {
        if (prime > n)
            return res;
        res += floor(n / prime);
    }
    return res;
}

int main()
{
    getFirstNPrimes();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int numTests;
    cin >> numTests;
    while (numTests--)
    {
        ll n;
        cin >> n;
        cout << comp(n) << endl;
    }
}