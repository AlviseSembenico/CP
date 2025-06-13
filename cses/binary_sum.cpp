
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int x = ~(a & b) & (a | b);
    cout << 2 * (a & b) + x;
    return 0;
}
