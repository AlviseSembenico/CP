#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
using namespace std;

void comp(int n, vector<int> arr)
{
    unordered_map<int, int> m;
    for (int i : arr)
        m[i]++;
    int a = 0, b = 0;
    for (int i : arr)
    {

        if (m[i] > 1)
        {
            m[i] = -1;
            a++;
            b++;
        }
        else
        {
            if (a > b)
            {
                m[i] = 2;
                b++;
            }
            else
            {
                m[i] = 1;
                a++;
            }
        }
    }
    cout << a * b << endl;
    a = 0;
    b = 0;
    for (int i : arr)
    {
        if (m[i] == 1)
        {
            a++;
            cout << 1 << ' ';
        }
        if (m[i] == 2)
        {
            b++;
            cout << 2 << ' ';
        }
        else
        {
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();
    string line;
    getline(cin, line);
    istringstream iss(line);
    int num;
    vector<int> arr;
    while (iss >> num)
    {
        arr.push_back(num);
    }
    comp(n, arr);
}
