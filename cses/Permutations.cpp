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
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << " ";
    }
    return os;
}

void comp(int size)
{
    if (size == 1)
    {
        cout << 1;
        return;
    }
    if (size <= 3)
    {
        cout << "NO SOLUTION" << endl;
        return;
    }
    if (size == 4)
    {
        vector<int> res = {2, 4, 1, 3};
        cout << res << endl;
        return;
    }
    int base = 1;
    while (base <= size)
    {
        cout << base << ' ';
        base += 2;
    }
    base = 2;
    while (base <= size)
    {
        cout << base << ' ';
        base += 2;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;
    comp(size);
}