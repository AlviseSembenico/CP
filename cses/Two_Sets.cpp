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

void comp(ll n)
{
    ll tot = n * (n + 1) / 2;
    if (tot % 2)
    {
        cout << "NO";
        return;
    }
    vector<int> s1;
    vector<int> s2;
    int ind = 0;
    vector<vector<int> *> vv = {&s1, &s2};
    s2.push_back(n);
    for (int i = n - 1; i > 1; i -= 2)
    {
        vv[ind]->push_back(i);
        vv[ind]->push_back(i - 1);
        ind = (ind + 1) % 2;
    }
    ll r1 = reduce(s1.begin(), s1.end(), 0LL);
    ll r2 = reduce(s2.begin(), s2.end(), 0LL);
    // cout << s1 << endl;
    // cout << s2 << endl;
    // cout << r1 << ' ' << r2 << endl;
    // if (r1 == r2)
    // {
    //     cout << "NO";
    //     return;
    // }
    if (min(s1.back(), s2.back()) != 1)
    {
        if (r1 < r2)
            s1.push_back(1);
        else
            s2.push_back(1);
    }
    cout << "YES" << endl;
    cout << s1.size() << endl;
    cout << s1 << endl;
    ;
    cout << s2.size() << endl;
    cout << s2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll size;
    cin >> size;
    comp(size);
}