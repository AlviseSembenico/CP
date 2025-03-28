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
#include "./codeforces/debug.hpp"
#endif

typedef long long ll;

ll comp(vector<vector<int>> &m)
{
    vector<int> nl;
    vector<int> nr;
    for (int i = 0; i < m.size(); i++)
    {
        if (m[i][0] == 0)
            nl.push_back(i);
        if (m[i][2] == 0)
            nr.push_back(i);
    }
    nr.push_back(INT_MAX);
    nl.push_back(nr.back() - 1);
    // printVector(nl);
    // printVector(nr);
    ll l = 1;
    ll r = 1;
    int lp = 0;
    int rp = 0;
    for (int i = 0; i < m.size(); i++)
    {
        ll add = 0;
        if (m[i][0] == 1)
            add += m[i][1];
        else
            add += l * (m[i][1] - 1);
        if (m[i][2] == 1)
            add += m[i][3];
        else
            add += r * (m[i][3] - 1);

        while (nr[rp] <= i)
            rp++;
        while (nl[lp] <= i)
            lp++;
        while (nr[rp] == nl[lp] && (rp != nr.size() - 1) && (lp != nl.size() - 1) && m[nr[rp]][1] == m[nr[rp]][3])
        {
            rp++;
            lp++;
        }
        if (nr[rp] > nl[lp] || (nr[rp] == nl[lp] && m[nr[rp]][1] > m[nr[rp]][3]))
            l += add;
        else
            r += add;
    }

    return l + r;
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
        vector<vector<int>> m;
        while (size--)
        {
            string s;
            vector<int> arr;
            cin >> s;
            int i;
            if (s == "+")
                arr.push_back(1);
            else
                arr.push_back(0);
            cin >> i;
            arr.push_back(i);
            cin >> s;
            if (s == "+")
                arr.push_back(1);
            else
                arr.push_back(0);
            cin >> i;
            arr.push_back(i);
            m.push_back(arr);
        }
        cout << comp(m) << endl;
    }
}