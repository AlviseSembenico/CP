
#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "./codeforces/debug.hpp"
#endif

typedef long long int ll;
typedef vector<int> vint;
typedef vector<ll> vlong;

#define all(x) x.begin(), x.end()

void ignoreLine()
{
    int n;
    cin >> n;
    int x;
    while (n--)
    {
        cin >> x;
    }
}

int main()
{
    int k = 0;
    while (true)
    {
        k++;
        cout << "next 0 1" << endl
             << flush;
        // read line and discard it
        ignoreLine();
        cout << "next 1" << endl
             << flush;

        int n;
        cin >> n;
        // read the rest of the input and ignore it
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
        }
        if (n == 2)
            break;
    }

    while (true)
    {
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl
             << flush;
        int n;
        cin >> n;
        // read the rest of the input and ignore it
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
        }

        if (n == 1)
            break;
    }
    cout << "done" << endl
         << flush;
}