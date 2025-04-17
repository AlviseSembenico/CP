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

typedef long long int ll;
void comp(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        ll total = 1LL * i * i * (i * i - 1) / 2;
        ll attack = 0;
        if (i > 2)
            attack = 4LL * (i - 1) * (i - 2);
        cout << total - attack << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;
    comp(numTests);
}