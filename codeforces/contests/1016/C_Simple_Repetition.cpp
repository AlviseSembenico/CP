#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
#include <climits>
#include <algorithm>

using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "./codeforces/debug.hpp"
#endif

typedef long long int ll;

bool isPrime64(long long x)
{
    if (x < 2)
        return false;
    if (x == 2 || x == 3)
        return true;
    if (x % 2 == 0 || x % 3 == 0)
        return false;
    for (long long i = 5; i * i <= x; i += 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    return true;
}

long long rep(long long n, int k)
{
    string s = to_string(n), result;
    result.reserve(s.size() * k);
    while (k--)
        result += s;
    return stoi(result);
}

string comp(ll n, ll k)
{
    // cout << n << " " << k << ' ' << isPrime[n] << endl;
    if (n != 1 && k != 1)
        return "NO";
    if (n == 1)
    {
        if (isPrime64(rep(1, k)))
            return "YES";
        return "NO";
    }
    if (k == 1)
    {
        if (isPrime64(n))
            return "YES";
        return "NO";
    }
    return "NO";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // fill(isPrime, isPrime + aim + 5, true);
    // getFirstNPrimes();
    int numTests;
    cin >> numTests;
    while (numTests--)
    {
        ll n, k;
        cin >> n >> k;
        cout << comp(n, k) << endl;
    }
}