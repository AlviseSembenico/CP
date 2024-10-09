#include <cmath>
#include <iostream>
#include <vector>
#include <istream>
#include <iterator>
#include <sstream>
#include <string>
#include <set>

using namespace std;

int missing(int n, vector<int> numbers)
{
    set<int> st(numbers.begin(), numbers.end());
    for (int i = 1; i <= n; i++)
        if (st.find(i) == st.end())
            return i;
    return 0;
}

int main()
{
    vector<int> numbers;
    string line;
    int n;
    getline(cin, line);
    n = stoi(line);
    getline(cin, line);

    int num;

    istringstream parser(line);

    numbers.insert(numbers.begin(),
                   istream_iterator<int>(parser), istream_iterator<int>());
    cout << missing(n, numbers);
}