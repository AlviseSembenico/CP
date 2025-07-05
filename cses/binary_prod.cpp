
#include <bits/stdc++.h>

using namespace std;

int sum(int a, int b)
{
    int x = ~(a & b) & (a | b);
    return 2 * (a & b) + x;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int res = 0;
    while (b > 0)
    {
        // cout << (b & 1) << " " << b << endl;
        if ((b & 1) == 1)
        {
            res = sum(res, a);
        }
        a <<= 1;
        b >>= 1;
    }
    cout << res << endl;
    return 0;
}
