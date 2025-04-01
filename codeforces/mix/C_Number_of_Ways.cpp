#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <set>
#include <map>
#include <numeric>
#include <climits>
using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "./codeforces/debug.hpp"
#endif

typedef long long int ll;

ll C(int n, int k)
{
    ll res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (ll)(res + 0.01);
}

ll comp(vector<int> &arr)
{
    ll target = reduce(arr.begin(), arr.end(), 0LL);
    if (target % 3 != 0)
        return 0;
    target = target / 3;
    ll partial = 0;
    if (target == 0)
    {
        int partial = 0;
        int c = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            partial += arr[i];
            if (partial == 0)
                c++;
        }

        return C(c - 1, 2);
    }

    vector<int> cnt(arr.size());
    ll prefix = 0;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        prefix += arr[i];
        if (prefix == target)
            cnt[i] = 1;
        else
            cnt[i] = 0;
    }
    ll res = 0;
    vector<int> cp(cnt);
    int com = 0;
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        cp[i] += cp[i + 1];
    }
    ll c = 0;
    for (int i = 0; i < arr.size() - 2; i++)
    {
        c += arr[i];
        if (c == target)
            res += cp[i + 2];
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;
    cin.ignore();
    vector<int> arr(size);

    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << comp(arr) << endl;
}