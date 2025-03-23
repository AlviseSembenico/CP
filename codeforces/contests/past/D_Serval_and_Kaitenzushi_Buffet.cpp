
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <numeric>
using namespace std;
#define DEBUG 1
#if DEBUG
#define HAS_EXTRA 1
#include "debug.hpp"
#endif

typedef long long ll;
const ll INF = 1e10 + 7; // or larger if needed
const ll NINF = -INF;

// ll comp(vector<ll> &dd, int k1)
// {
//     int nplates = floor(dd.size() / k1);
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout << NINF << endl;
    int numTests;
    cin >> numTests;
    while (numTests--)
    {
        int size, k;
        cin >> size >> k;
        cin.ignore();
        vector<ll> arr(size);
        for (int i = 0; i < size; i++)
            cin >> arr[i];
        // printVector(arr);
        // cout << comp(arr, k) << endl;
    }
}