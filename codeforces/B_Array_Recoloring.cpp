
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;

long long compute(vector<long long> &arr, long long k)
{
    if (k >= arr.size() + 1)
        return reduce(arr.begin(), arr.end());
    if (k == 1)
    {
        auto me_n = max_element(arr.begin(), arr.end());
        long long me_ind = distance(arr.begin(), me_n);
        if (me_ind != 0 && me_ind != arr.size() - 1)
            return *me_n + max(arr[0], arr.back());
    }
    sort(arr.begin(), arr.end());
    return accumulate(arr.end() - k - 1, arr.end(), (long long)0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long numTests;
    cin >> numTests;
    while (numTests--)
    {
        long long n, k;
        cin >> n >> k;
        cin.ignore();
        string line;
        getline(cin, line);
        istringstream iss(line);
        long long num;
        vector<long long> arr;
        while (iss >> num)
        {
            arr.push_back(num);
        }
        // prlong longVector(arr);
        cout << compute(arr, k) << endl;
    }
}