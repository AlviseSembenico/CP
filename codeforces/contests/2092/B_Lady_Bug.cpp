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
#include "debug.hpp"
#endif

void comp(string s, string t)
{
    int odd = 0;
    int even = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 0)
            even += (s[i] == '1');
        else
            odd += (s[i] == '1');
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 1)
            even += (t[i] == '1');
        else
            odd += (t[i] == '1');
    }
    if (odd <= (s.size() + 1) / 2 && even <= (s.size() / 2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
        string s, t;
        getline(cin, s);
        getline(cin, t);
        comp(s, t);
    }
}