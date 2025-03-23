
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
using namespace std;

int comp(int k, vector<bool> arr)
{
    int n = arr.size();
    vector<int> suffix(arr.size());
    if (arr.back())
        suffix[n - 1] = 1;
    else
        suffix[n - 1] = -1;
    for (int i = n - 2; i > 0; i--)
    {
        if (arr[i])
            suffix[i] = suffix[i + 1] + 1;
        else
            suffix[i] = suffix[i + 1] - 1;
    }
    suffix[0] = 0;
    sort(suffix.begin(), suffix.end());
    reverse(suffix.begin(), suffix.end());
    int count = 0;
    long long int res = 0;
    for (int s : suffix)
    {
        res += s;
        count++;
        if (res >= k)
            return count + 1;
    }
    return -1;
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
        cin >> n;
        cin >> k;
        cin.ignore();
        string line;
        getline(cin, line);
        vector<bool> fish;
        for (char c : line)
        {
            if (c == '1')
                fish.push_back(true);
            else
                fish.push_back(false);
        }
        cout << comp(k, fish) << endl;
    }
}