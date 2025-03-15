#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <random>
using namespace std;

void comp(int n)
{
    random_device rd; // a seed source for the random number engine
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 3);
    int num[3];
    num[0] = 1;
    num[1] = 2;
    num[2] = 3;
    int res = 1;
    while (res != 0)
    {
        cout << "? " << num[0] << ' ' << num[1] << ' ' << num[2] << endl
             << flush;
        cin >> res;
        if (res == 0)
            break;
        num[distrib(gen)] = res;
    }
    cout << "! " << num[0] << ' ' << num[1] << ' ' << num[2] << endl
         << flush;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;
    while (numTests--)
    {
        int n;
        cin >> n;
        cin.ignore();
        comp(n);
    }
}