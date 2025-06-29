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

#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))

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
        vector<int> arr(size);

        for (int i = 0; i < size; i++)
            cin >> arr[i];
    }
}