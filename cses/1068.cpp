#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<long unsigned int> weird_algo(long unsigned int n)
{
    vector<long unsigned int> res;
    while (n != 1)
    {
        // cout << n << endl;
        res.push_back(n);
        if (n % 2)
            n = n * 3 + 1;
        else
            n /= 2;
    }
    res.push_back(1);
    return res;
}

int main()
{
    int n;
    cin >> n;
    // n = 665215;
    vector<long unsigned int> res;
    res = weird_algo(n);
    for (long unsigned int a : res)
        cout << a << ' ';
}