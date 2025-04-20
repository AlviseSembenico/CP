#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <numeric>
#include <climits>
#include <map>
using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "debug.hpp"
#endif

typedef long long int ll;

void comp(string &s)
{

    map<char, int> mp;
    for (char c : s)
        mp[c]++;

    if (mp.size() == 1)
    {
        cout << -1 << endl;
        return;
    }

    int target = max(mp['T'], max(mp['I'], mp['L']));
    int nops = 3 * target - mp['T'] - mp['I'] - mp['L'];
    char most;
    int ta = 0, tb = 0;
    char ca;
    char cb;
    if (mp['T'] == target)
    {
        ta = target - mp['I'];
        tb = target - mp['L'];
        ca = 'I';
        cb = 'L';
        most = 'T';
    }
    else if (mp['I'] == target)
    {
        ta = target - mp['T'];
        tb = target - mp['L'];
        ca = 'T';
        cb = 'L';
        most = 'I';
    }
    else
    {
        ta = target - mp['T'];
        tb = target - mp['I'];
        ca = 'T';
        cb = 'I';
        most = 'L';
    }
    vector<int> tt = {ta, tb};
    sort(tt.begin(), tt.end());
    int current = 1;
    vector<int> ops;
    // cout << nops << endl;
    // return;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if ((s[i] != most && s[i + 1] == most))
        {
            int counter = 1;
            while (tt[current] > 0)
            {
                ops.push_back(i + counter);
                tt[current]--;
                current = 1 - current;
                counter++;
            }
        }
        if ((s[i] == most && s[i + 1] != most))
        {
            while (tt[current] > 0)
            {
                ops.push_back(i + 1);
                tt[current]--;
                current = 1 - current;
            }
        }
        current = 1;
        sort(tt.begin(), tt.end());
    }
    if (tt[0] > 0 || tt[1] > 0)
    {
        cout << -1 << endl;
        return;
    }
    cout << ops.size() << endl;
    for (int i : ops)
        cout << i << endl;
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
        string s;
        getline(cin, s);
        comp(s);
    }
}