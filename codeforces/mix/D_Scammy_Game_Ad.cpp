
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
    nr.push_back(1e10);
    nl.push_back(nr.back() - 1);
    int l = 1;
    int r = 1;
    int lp = 0;
    int rp = 0;
    for (int i = 0; i < m.size(); i++)
    {
        // cout << l << "  " << r << endl;
        int add = 0;
        if (m[i][0] == 1)
            add += m[i][1];
        else
            add += l * (m[i][1] - 1);
        if (m[i][2] == 1)
            add += m[i][3];
        else
            add += r * (m[i][3] - 1);
        while (nr[rp] == nl[lp])
        {
            rp++;
            lp++;
        }
        if (nr[rp] > nl[lp])
            l += add;
        else
            r += add;
        if (nr[rp] <= i)
            rp++;
        if (nl[lp] <= i)
            lp++;
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