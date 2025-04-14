#include <cmath>
#include <iostream>
#include <vector>
#include <istream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
typedef long long int lint;

void print(vector<int> v)
{
    cout << "[";
    for (int i : v)
        cout << i << ", ";
    cout << "]" << endl;
}

int fix(vector<int> &v1, vector<int> &v2, int diff)
{

    int t1 = reduce(v1.begin(), v1.end());
    int t2 = reduce(v2.begin(), v2.end());
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v2.size(); j++)
        {
            int e1 = v1[i];
            int e2 = v2[j];
            // int ndiff = abs((t1 - t2 - 2 * e1 + 2 * e2));
            int ndiff = abs((t1 - e1 + e2) - (t2 + e1 - e2));
            if (ndiff < diff)
            {
                v1.push_back(e2);
                v1.erase(v1.begin() + i);
                v2.push_back(e1);
                v2.erase(v2.begin() + j);
                return ndiff;
            }
        }
    }
    return diff;
}
lint apple_division(lint n, vector<int> numbers)
{
    vector<int> v1 = numbers;
    vector<int> v2;
    for (int i = 0; i < numbers.size(); i++)
        v2.push_back(0);

    int t1 = reduce(v1.begin(), v1.end());
    int t2 = 0;
    int diff = t1 - t2;
    while (true)
    {
        cout << diff << endl;
        int diff2 = fix(v1, v2, diff);
        print(v1);
        cout << "------" << endl;
        print(v2);
        cout << "------" << endl;
        if (diff2 == diff)
            return diff;
        diff = diff2;
    }
    return -1;
}

lint min_difference(int n, vector<int> &weights)
{
    lint total_weight = 0;
    for (int weight : weights)
    {
        total_weight += weight;
    }

    lint min_diff = total_weight; // Start with max possible difference

    // There are 2^n possible subsets for n apples
    for (int i = 0; i < (1 << n); ++i)
    {
        lint subset_sum = 0;
        // Calculate the sum of the current subset
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))
            {
                subset_sum += weights[j];
            }
        }
        // The other group will have the remaining weight
        lint other_group_sum = total_weight - subset_sum;
        // Calculate the difference between the two groups
        lint diff = abs(subset_sum - other_group_sum);
        // Update the minimum difference
        min_diff = min(min_diff, diff);
    }

    return min_diff;
}

int main()
{
    vector<int> numbers;
    string line;
    lint n;
    getline(cin, line);
    n = stoi(line);
    getline(cin, line);

    lint num;

    istringstream parser(line);

    numbers.insert(numbers.begin(),
                   istream_iterator<int>(parser), istream_iterator<int>());
    cout << min_difference(n, numbers);
}
