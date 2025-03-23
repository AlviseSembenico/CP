
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <numeric>
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

void comp(vector<int> l)
{
    int deleted = 0;
    vector<string> ops;
    bool acted = false;
    for (int i = 0; i < l.size(); i++)
    {
        int v = l[i];
        if (v == 0 && !acted)
        {
            if (i != l.size() - 1)
            {
                ops.push_back(to_string(i + 1 - deleted) + " " + to_string(i + 2 - deleted));
                acted = true;
                deleted++;
            }
            else
            {
                ops.push_back(to_string(i - deleted) + " " + to_string(i + 1 - deleted));
                acted = true;
                deleted++;
            }
        }
        else
            acted = false;
    }

    cout << ops.size() + 1 << endl;
    for (auto s : ops)
        cout << s << endl;
    cout << 1 << " " << l.size() - deleted << endl;
}

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
        comp(arr);
    }
}