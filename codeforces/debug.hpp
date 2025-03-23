#include <vector>
#include <string>
#include <iostream>
using namespace std;

void printVector(const vector<long long int> &vec, const string &separator = ", ", const string &prefix = "[", const string &suffix = "]")
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

inline void printMap(const map<int, int> &m)
{
    cout << "{ ";
    for (auto [k, v] : m)
    {
        cout << k << ": " << v << ", ";
    }
    if (!m.empty())
        cout << "\b\b "; // erase last comma
    cout << "}\n";
}
