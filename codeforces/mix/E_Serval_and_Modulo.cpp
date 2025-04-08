
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <numeric>
using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "codeforces/debug.hpp"
#endif

typedef long long ll;
const ll C = 1e6 + 5;

int cnt[C];

bool check(vector<int> &a, vector<int> &b, ll k, int n)
{
    for (int i = 0; i < n; i++)
        cnt[a[i] % k]++;
    for (int i = 0; i < n; i++)
        if (--cnt[b[i]] < 0)
        {
            cnt[b[i]] = 0;
            for (int i = 0; i < n; i++)
                cnt[a[i] % k] = 0;
            return 0;
        }
    return 1;
}

long long int solve(vector<int> &a, vector<int> &b, int n)
{
    ll t = 0;
    for (int i = 0; i < n; i++)
        t += a[i] - b[i];
    ll c = 1;
    ll res = 0;
    if (t == 0)
    {
        for (int i = 0; i < n; i++)
            res = max(res, (ll)a[i]);
        res++;
        if (check(a, b, res, n))
            return res;
        return -1;
    }
    while (c * c <= t) // TODO: optimize this max loop
    {
        if (t % c == 0)
        {
            if (check(a, b, c, n))
                return c;
            if (c < C && check(a, b, t / c, n))
                return t / c;
        }
        c++;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;
    vector<int> arr(C);
    vector<int> arr2(C);
    while (numTests--)
    {
        int size;
        cin >> size;
        cin.ignore();
        for (int i = 0; i < size; i++)
            cin >> arr[i];
        for (int i = 0; i < size; i++)
            cin >> arr2[i];
        cout << solve(arr, arr2, size) << endl;
    }
}