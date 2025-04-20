
#include <bits/stdc++.h>

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

int counter[30] = {};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    for (char c : s)
        counter[c - 'A']++;

    char mid;
    int ind = -1;
    for (int i = 0; i < 30; i++)
    {
        if (counter[i] % 2)
        {
            if (ind >= 0)
            {
                cout << "NO SOLUTION";
                return 0;
            }
            ind = i;
            mid = 'A' + i;
        }
    }
    string res = "";
    for (int i = 0; i < 30; i++)
    {
        char c = 'A' + i;
        if (i != ind)
            for (int j = 0; j < counter[i] / 2; j++)
                res += c;
    }
    string mids;
    for (int i = 0; i < counter[ind]; i++)
        mids += mid;

    string rres = string(res.rbegin(), res.rend());
    cout << res + mids + rres;
    // cout << mids << endl;
    // cout << res << endl;
}