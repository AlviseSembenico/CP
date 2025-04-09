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

bool check(vector<int> &nums, int target, int k)
{
    // cout << target << ' ' << k << endl;
    unordered_set<int> seen;
    int current = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (current >= target)
        {
            k--;
            seen.clear();
            current = 0;
        }

        int val = nums[i];
        if (val == current)
        {
            current++;
            while (seen.contains(current))
                current++;
        }
        seen.insert(val);
    }
    if (current >= target)
        k--;
    // cout << target << ' ' << k << endl;
    return k <= 0;
}

int comp(vector<int> &nums, int k)
{
    int i = 0;
    int j = *max_element(nums.begin(), nums.end()) + 1;
    while (i < j - 1)
    {
        int mid = (i + j) / 2;
        if (check(nums, mid, k))
            i = mid;
        else
            j = mid;
    }
    if (check(nums, j, k))
        return j;
    return i;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;
    while (numTests--)
    {
        int size, k;
        cin >> size >> k;
        cin.ignore();
        vector<int> arr(size);

        for (int i = 0; i < size; i++)
            cin >> arr[i];
        cout << comp(arr, k) << endl;
    }
}