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

void comp(vector<string> &res, string current, unordered_map<char, int> &m)
{
    if (m.size() == 0)
    {
        res.push_back(current);
        return;
    }
    for (auto &[k, c] : m)
    {
        unordered_map<char, int> nm(m);
        nm[k]--;
        if (c == 1)
            nm.erase(k);
        comp(res, current + k, nm);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    vector<string> res;
    unordered_map<char, int> m;
    for (char c : s)
        m[c]++;
    comp(res, "", m);
    cout << res.size() << endl;
    sort(res.begin(), res.end());
    for (auto s : res)
        cout << s << endl;
}