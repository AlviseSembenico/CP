
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>

#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
#include <climits>
#include <algorithm>
#include <optional>

using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "./codeforces/debug.hpp"
#endif

typedef long long int ll;

class Table
{

public:
    int x;
    int y;
    int taken = 0;
    Table(int x, int y) : x(x), y(y) {}

    int distance() const
    {
        int res = 0;
        switch (taken)
        {
        case 0:
            res = x + y;
            break;
        case 1:
            res = x + y + 1;
            break;
        case 2:
            res = x + y + 1;
            break;
        case 3:
            res = x + y + 3 + 1;
            break;
        }
        return res;
    }

    bool operator<(const Table &other) const
    {
        if (distance() != other.distance())
            return distance() < other.distance();
        if (x_pos() != other.x_pos())
            return x_pos() < other.x_pos();
        return y_pos() < other.y_pos();
    }

    bool operator>(const Table &other) const
    {
        return other < *this;
    }

    int x_pos() const
    {
        switch (taken)
        {
        case 0:
            return x;
        case 1:
            return x;
        case 2:
            return x + 1;
        case 3:
            return x + 1;
        }
    }

    int y_pos() const
    {
        switch (taken)
        {
        case 0:
            return y;
        case 1:
            return y + 1;
        case 2:
            return y;
        case 3:
            return y + 1;
        }
    }

    void occupy()
    {
        switch (taken)
        {
        case 0:
            cout << x << ' ' << y << endl;
            break;
        case 1:
            cout << x << ' ' << y + 1 << endl;
            break;
        case 2:
            cout << x + 1 << ' ' << y << endl;
            break;
        case 3:
            cout << x + 1 << ' ' << y + 1 << endl;
            break;
        }

        taken++;
    }
};

void solve(vector<int> guests)
{
    priority_queue<Table, vector<Table>, greater<Table>> unused;
    priority_queue<Table, vector<Table>, greater<Table>> used;
    for (int i = 1; i < 6 * (int)sqrt(guests.size()); i = i + 3)
        for (int j = 1; j < 6 * (int)sqrt(guests.size()); j = j + 3)
            unused.push(Table(i, j));

    for (int g : guests)
    {
        optional<Table> t;
        if (g)
        {
            if (used.size() == 0 || unused.top().distance() < used.top().distance())
            {
                t = unused.top();
                unused.pop();
            }
            else
            {
                t = used.top();
                used.pop();
            }
        }
        else
        {
            t = unused.top();
            unused.pop();
        }
        t->occupy();
        if (t->taken == 4)
            continue;
        used.push(*t);
    }
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
        solve(arr);
    }
}