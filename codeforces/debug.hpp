#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

// Define a concept for allowed types
template <typename T>
concept AllowedType = std::same_as<T, int> || std::same_as<T, long long>;

template <AllowedType T>
void printVector(const vector<T> &vec, const string &separator = ", ", const string &prefix = "[", const string &suffix = "]")
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

template <AllowedType T>
void printVector(T vec[], int size, const string &separator = ", ", const string &prefix = "[", const string &suffix = "]")
{
    cout << prefix;
    for (size_t i = 0; i < size; ++i)
    {
        cout << vec[i];
        if (i < size - 1)
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
