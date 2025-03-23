

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <cmath>
using namespace std;

void printVector(const vector<int> &vec, const string &separator = ", ", const string &prefix = "[", const string &suffix = "]")
{
    cout << prefix;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i];
        if (i < vec.size() - 1)
        {
            cout << separator;
        }
    }
    cout << suffix << endl;
}

long long comp(long long a, long long b)
{
    // cout << a << ' ' << b << endl;
    if (a == b)
        return -1;
    return (1LL << (int)ceil(log2(max(a, b)))) - max(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;
    while (numTests--)
    {
        long long int a, b;
        cin >> a >> b;
        cout << comp(a, b) << endl;
    }
}