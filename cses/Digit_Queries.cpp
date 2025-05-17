
#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "./codeforces/debug.hpp"
#endif

typedef long long int ll;

int comp(ll q)
{
    if (q < 9)
        return q;
    int size = 2;
    ll tot = 9;
    int i = 0;
    while (tot + (pow(10, size) - pow(10, size - 1) - 1) * size < q)
    {
        tot += (pow(10, size) - pow(10, size - 1) - 1) * size;
        size++;
    }
    q -= tot;
    int digit = ((q - 1) % size);
    if (digit == 0)
    {
        return 1 + floor(q / (pow(10, size - 1) * size));
    }
    return q / ((q - 1) * size) - 1;
}

char comp1(ll k)
{
    ll len = 1, count = 9, start = 1;
    while (k > len * count)
    {
        k -= len * count;
        len++;
        count *= 10;
        start *= 10;
    }
    start += (k - 1) / len;
    string s = to_string(start);
    return s[(k - 1) % len];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;
    while (numTests--)
    {
        ll q;
        cin >> q;
        cout << comp1(q) << endl;
    }
}