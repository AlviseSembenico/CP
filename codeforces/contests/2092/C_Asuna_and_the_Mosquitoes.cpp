#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <numeric>
#include <climits>
#include <set>
using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "debug.hpp"
#endif

typedef long long int ll;

ll comput(vector<int> &arr)
{
    int m = *max_element(arr.begin(), arr.end());
    int odd = 0;
    int even = 0;
    for (auto n : arr)
    {
        if (n % 2 == 0)
            even++;
        else
            odd++;
    }

    if (odd == 0 || even == 0)
        return m;
    ll sum = reduce(arr.begin(), arr.end(), 0LL);
    return sum - (odd - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;
    while (numTests--)
    {
        int size;
        cin >> size;
        cin.ignore();
        vector<int> arr(size);

        for (int i = 0; i < size; i++)
            cin >> arr[i];

        cout << comput(arr) << endl;
    }
}