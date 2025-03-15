#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// The comp function replicates the logic of the Python version.
// It returns a pair: first element is the best segment's length,
// and second element is a pair of indices (start, end) if best > 0.
// (If best==0, it means no valid segment was found, which corresponds to returning 0 in Python.)
pair<int, pair<int, int>> comp(const vector<int> &arr)
{
    unordered_map<int, int> freq;
    for (int num : arr)
        freq[num]++;

    // Build a set of elements that appear more than once.
    unordered_set<int> repeated;
    for (const auto &p : freq)
        if (p.second > 1)
            repeated.insert(p.first);

    int i = 0;
    int best = 0;
    pair<int, int> ans = {0, 0};
    for (int j = 0; j < (int)arr.size(); j++)
    {
        if (repeated.find(arr[j]) != repeated.end())
        {
            i = j + 1;
            continue;
        }
        if (j - i + 1 >= best)
        {
            best = j - i + 1;
            ans = {i, j};
        }
    }
    return {best, ans};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        vector<int> arr(m);
        for (int i = 0; i < m; i++)
        {
            cin >> arr[i];
        }
        auto result = comp(arr);
        int best = result.first;
        // If best==0, output 0 (like the Python branch for int return type)
        if (best == 0)
            cout << 0 << "\n";
        else
        {
            // Output 1-indexed indices
            cout << result.second.first + 1 << " " << result.second.second + 1 << "\n";
        }
    }
    return 0;
}
