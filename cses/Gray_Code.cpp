#include <bits/stdc++.h>

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
vector<vector<string>> g;

void populate(string current, bool seen[])
{
    int ind = stoi(current, nullptr, 2);
    if (seen[ind])
        return;

    seen[ind] = true;
    for (int i = 0; i < current.size(); i++)
    {
        string nc(current);
        nc[i] = nc[i] == '1' ? '0' : '1';
        int toInd = stoi(nc, nullptr, 2);
        g[ind].push_back(nc);
        g[toInd].push_back(current);
        populate(nc, seen);
    }
}

void compose(string current, vector<string> &res, bool seen[])
{
    int ind = stoi(current, nullptr, 2);
    seen[ind] = true;
    res.push_back(current);
    for (string s : g[ind])
    {
        int i = stoi(s, nullptr, 2);
        if (!seen[i])
            return compose(s, res, seen);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string start = "";
    for (int i = 0; i < n; i++)
        start += '0';
    g.resize(pow(2, n) + 3);

    int size = (int)pow(2, n) + 3;
    bool seen[size] = {false};
    populate(start, seen);
    fill(seen, seen + size, false);
    vector<string> res;
    compose(start, res, seen);
    for (string s : res)
        cout << s << endl;
}