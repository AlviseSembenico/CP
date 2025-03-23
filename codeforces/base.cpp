#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <numeric>
using namespace std;

#define DEBUG 1

#if DEBUG
#define HAS_EXTRA 1
#include "debug.hpp"
#endif

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
    }
}