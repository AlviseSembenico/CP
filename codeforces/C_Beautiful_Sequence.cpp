
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <set>
using namespace std;
#define MOD 998244353

vector<int> arr;

long long unsigned int comp()
{
    int n = arr.size();
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            c1 += 1;
            c1 %= MOD;
        }
        if (arr[i] == 2)
        {
            c2 += c2;
            c2 += c1;
            c2 %= MOD;
        }
        if (arr[i] == 3)
        {
            c3 += c2;
            c3 %= MOD;
        }
    }
    return c3;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;
    int i = 1;
    while (numTests--)
    {
        arr = {};
        int size;
        cin >> size;
        cin.ignore();
        string line;
        getline(cin, line);
        istringstream iss(line);
        int num;
        while (iss >> num)
        {
            arr.push_back(num);
        }
        int n = 0;
        for (int i : arr)
            if (i == 2)
                n++;
        cout << comp() << endl;
    }
}