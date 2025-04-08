
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <numeric>
#include <climits>

using namespace std;

#define DEBUG 1

#if DEBUG
#define HAS_EXTRA 1
#include "./codeforces/debug.hpp"
#endif
typedef long long ll;

unordered_map<ll, double> p;
ll inv2 = 5e8 + 4;
ll mod = 1e9 + 7;

// double comp(string n, int size)
// {
//     int res = 0;
//     for (int i = n.size() - 1; i >= 0; i--)
//     {
//         res = (res + (n[i] == '1')) * inv2 % mod;
//     }
//     return (size - 1 + res) % mod;
// }

double comp(string n, int size)
{
    long long res = 0;
    // Start from the rightmost bit down to index 1 (skip the most significant bit at index 0)
    for (int i = n.size() - 1; i >= 1; i--)
    {
        if (n[i] == '1')
            res = (res + 1) % mod;
        res = (res * inv2) % mod;
    }
    // Add the base (size - 1) then take mod
    long long ans = ((size - 1) + res) % mod;
    return ans; // Returning as a double, but it's an integer modded result.
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;
    while (numTests--)
    {
        int n;
        cin >> n;
        string number;
        cin >> number;
        double res = comp(number, n);
        cout << res << endl;
    }
}