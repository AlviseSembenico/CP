#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <algorithm>
#include <thread>
#include <atomic>
#include <optional>
#include <mutex>
#include <numeric>

using namespace std;

const int gridSize = 5;
const array<pair<int, int>, 8> moves = {{{2, 1}, {-2, 1}, {1, 2}, {-1, 2}, {2, -1}, {-2, -1}, {1, -2}, {-1, -2}}};
array<array<int, 6>, 6> inputArray = {{{0, 1, 1, 2, 2, 2},
                                       {0, 1, 1, 2, 2, 2},
                                       {0, 0, 1, 1, 2, 2},
                                       {0, 0, 1, 1, 2, 2},
                                       {0, 0, 0, 1, 1, 2},
                                       {0, 0, 0, 1, 1, 2}}};
array<array<int, 6>, 6> rotatedArray;
atomic<int> activeThreads{0};

int getValue(int x, int y, int a, int b, int c)
{
    int value = inputArray[x][y];
    if (value == 0)
    {
        return a;
    }
    else if (value == 1)
    {
        return b;
    }
    else
    {
        return c;
    }
}

void printPath(const vector<pair<int, int>> &path)
{
    for (auto &pos : path)
    {
        cout << "(" << pos.first << ", " << pos.second << ") ";
    }
    cout << endl;
}

optional<vector<pair<int, int>>> generate(const vector<pair<int, int>> &path, int a, int b, int c, int score, bool top)
{
    // printPath(path);
    // cout << "Score: " << score << endl;
    int endx = top ? gridSize : 0;
    int endy = gridSize;
    auto pos = path.back();
    if (pos.first == endx && pos.second == endy && score == 2024)
    {
        return path;
    }
    int prevValue = getValue(pos.first, pos.second, a, b, c);
    for (auto &move : moves)
    {
        pair<int, int> new_pos = {pos.first + move.first, pos.second + move.second};
        // check if the new position is out of bounds
        if (new_pos.first > gridSize || new_pos.first < 0 || new_pos.second > gridSize || new_pos.second < 0)
        {
            continue;
        }
        // check if the new position is already been visited
        if (find(path.begin(), path.end(), new_pos) != path.end())
        {
            continue;
        }
        int value = getValue(new_pos.first, new_pos.second, a, b, c);
        int new_score = score;

        if (value == prevValue)
            new_score += value;
        else
            new_score *= value;
        if (new_score > 2024)
            continue;

        vector<pair<int, int>> new_path = path;
        new_path.push_back(new_pos);
        optional<vector<pair<int, int>>> res = generate(new_path, a, b, c, new_score, top);
        if (res != nullopt)
        {
            return res;
        }
    }

    return nullopt;
}

int main()
{
    int ub = 50;
    vector<int> c_values = {11, 23, 2, 4, 8, 22, 44, 46};

    vector<array<int, 3>> combinations;
    // generate all combinations
    for (int a = 1; a < ub; a++)
        for (int b = 1; b < ub; b++)
            for (int c : c_values)
                if (a + b + c < ub)
                    combinations.push_back(array<int, 3>{a, b, c});
    // sort
    sort(combinations.begin(), combinations.end(), [](const array<int, 3> &a, const array<int, 3> &b)
         { return accumulate(a.begin(), a.end(), 0) < accumulate(b.begin(), b.end(), 0); });
    reverse(combinations.begin(), combinations.end());

    cout << combinations.size() << endl;
    for (int i = 0; i < combinations.size(); i++)
    {
        cout << i << endl;
        array<int, 3> values = combinations[i];
        int a = values[0];
        int b = values[1];
        int c = values[2];
        vector<pair<int, int>> startPath = {{0, 0}};
        optional<vector<pair<int, int>>> pathTop = generate(startPath, a, b, c, a, true);
        if (pathTop == nullopt)
            continue;
        startPath = {{5, 0}};
        optional<vector<pair<int, int>>> pathBottom = generate(startPath, a, b, c, a, false);
        if (pathBottom == nullopt)
            continue;
        // found a good one

        // print paths and a,b,c
        cout << "a: " << a << " b: " << b << " c: " << c << endl;
        cout << "Top Path: ";
        for (auto &pos : pathTop.value())
        {
            cout << "(" << pos.first << ", " << pos.second << ") ";
        }
        cout << endl;
        cout << "Bottom Path: ";
        for (auto &pos : pathBottom.value())
        {
            cout << "(" << pos.first << ", " << pos.second << ") ";
        }
    }

    return 0;
}
