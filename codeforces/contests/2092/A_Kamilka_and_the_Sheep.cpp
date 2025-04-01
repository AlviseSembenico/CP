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

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "codeforces/debug.hpp"
#endif
typedef long long int ll;

ll comp(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    return arr.back() - arr[0];
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
        cout << comp(arr) << endl;
    }
}