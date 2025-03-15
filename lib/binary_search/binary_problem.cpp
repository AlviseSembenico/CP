#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>

bool check(int target)
{
    /*
    This functions checks if a given target is obtainable
    */
}

int binary_search(vector<int> &nums, int k)
{
    int i = 0;
    int j = 1e4; // Search space
    while (i < j - 1)
    {
        int mid = (i + j) / 2;
        if (check(mid))
            j = mid;
        else
            i = mid;
    }
    if (check(mid))
        return i;
    return j;
}
