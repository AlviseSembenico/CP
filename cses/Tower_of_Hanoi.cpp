
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
int arr[] = {
    1, 3, 7, 15, 31, 63, 127, 255,
    511, 1023, 2047, 4095, 8191, 16383, 32767, 65535};

void solve(int n, int from, int to)
{
    if (n == 1)
    {
        cout << from << ' ' << to << endl;
        return;
    }
    int nt = 6 - from - to;
    solve(n - 1, from, nt);
    cout << from << ' ' << to << endl;
    solve(n - 1, nt, to);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << arr[n - 1] << endl;
    solve(n, 1, 3);
}