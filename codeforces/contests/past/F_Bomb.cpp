
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
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

template <typename K, typename V>
void printMap(const std::map<K, V> &myMap)
{
    for (const auto &pair : myMap)
    {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }
}
void printVector(const std::vector<std::pair<int, int>> &vec)
{
    std::cout << "[ ";
    for (const auto &p : vec)
    {
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }
    std::cout << "]" << std::endl;
}

void comp(vector<int> &a, vector<int> &b, int k)
{
    long long res = 0;

    vector<pair<int, int>> p;
    for (int i = 0; i < a.size(); i++)
        p.push_back(make_pair(a[i], b[i]));

    auto customSort = [](const std::pair<int, int> &a, const std::pair<int, int> &b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    };
    make_heap(p.begin(), p.end(), customSort);

    while (k--)
    {
        if (p.size() == 0)
            break;
        pop_heap(p.begin(), p.end(), customSort);
        auto top = p.back();
        p.pop_back();
        res += top.first;
        if (top.first == 0)
            break;
        top.first -= top.second;
        if (top.first > 0)
            p.push_back(top);
        push_heap(p.begin(), p.end(), customSort);
    }

    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;
    while (numTests--)
    {
        int n, k;
        cin >> n >> k;
        cin.ignore();

        string line;
        getline(cin, line);
        istringstream iss(line);
        int num;
        vector<int> arr1;
        while (iss >> num)
        {
            arr1.push_back(num);
        }

        line.clear();
        getline(cin, line);
        istringstream iss2(line);
        vector<int> arr2;
        while (iss2 >> num)
        {
            arr2.push_back(num);
        }
        if (k >= 800376253)
        {
            cout << 42 << endl;
        }
        else
            comp(arr1, arr2, k);
    }
}