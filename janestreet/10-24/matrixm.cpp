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

mutex cout_mutex;

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

optional<vector<pair<int, int>>> generate(const vector<pair<int, int>> &path, int a, int b, int c, int score, bool top)
{
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

struct res
{
    int a;
    int b;
    int c;
    vector<pair<int, int>> pathTop;
    vector<pair<int, int>> pathBottom;
};

vector<res> results;

void process_combinations(int start, int end, const vector<array<int, 3>> &combinations)
{
    for (int i = start; i < end; ++i)
    {
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
        res r;
        r.a = a;
        r.b = b;
        r.c = c;
        r.pathTop = pathTop.value();
        r.pathBottom = pathBottom.value();
        results.push_back(r);
        // print paths and a,b,c
        {
            lock_guard<mutex> lock(cout_mutex);
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
            cout << endl;
        }
    }
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
    cout << "Total combinations: " << combinations.size() << endl;

    unsigned int numThreads = thread::hardware_concurrency();
    if (numThreads == 0)
        numThreads = 16; // Default to 4 threads if unable to detect

    vector<thread> threads;
    int combinationsPerThread = combinations.size() / numThreads;
    int start = 0;

    for (unsigned int t = 0; t < numThreads; ++t)
    {
        int end = start + combinationsPerThread;
        if (t == numThreads - 1)
            end = combinations.size(); // Last thread processes the remaining combinations
        threads.emplace_back(process_combinations, start, end, ref(combinations));
        start = end;
    }

    for (auto &t : threads)
    {
        t.join();
    }
    // write all combination, sorted by score.a+score.b+score.c
    sort(results.begin(), results.end(), [](const res &a, const res &b)
         { return a.a + a.b + a.c < b.a + b.b + b.c; });
    for (int i = 0; i < results.size(); i++)
    {
        cout << "a: " << results[i].a << " b: " << results[i].b << " c: " << results[i].c << endl;
        cout << "Top Path: ";
        for (auto &pos : results[i].pathTop)
        {
            cout << "(" << pos.first << ", " << pos.second << ") ";
        }
        cout << endl;
        cout << "Bottom Path: ";
        for (auto &pos : results[i].pathBottom)
        {
            cout << "(" << pos.first << ", " << pos.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
