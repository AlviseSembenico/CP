#include <cmath>
#include <iostream>
#include <vector>
#include <istream>
#include <iterator>
#include <sstream>
#include <string>
#include <set>

using namespace std;

int repetitions(string s)
{
    char p = '2';
    int m = 0;
    int current = 0;
    for (char &c : s)
    {
        if (c == p)
            current++;
        else
        {
            current = 1;
        }
        p = c;
        m = max(m, current);
    }
    return m;
}

int main()
{
    string line;
    getline(cin, line);

    cout << repetitions(line);
}