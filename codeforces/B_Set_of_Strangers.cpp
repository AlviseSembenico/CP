

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
using namespace std;

vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int comp(vector<vector<int>> mat)
{
    unordered_set<int> s;
    for (vector<int> a : mat)
    {
        for (int i : a)
            s.insert(i);
    }
    int res = 0;
    bool d = false;
    unordered_map<int, bool> contiguous;
    // cout << "-----" << endl;
    // cout << mat.size() << " " << mat[0].size() << endl;
    for (int i = 0; i < mat.size(); i++)
        for (int j = 0; j < mat[0].size(); j++)
        {
            int n = mat[i][j];
            for (vector<int> move : moves)
            {
                int ni = i + move[0];
                int nj = j + move[1];
                if (ni < 0 || ni >= mat.size() || nj < 0 || nj >= mat[0].size())
                    continue;
                if (mat[ni][nj] == n)
                    contiguous[n] = true;
            }
        }

    for (int el : s)
    {
        if (contiguous[el])
        {
            res += 2;
            d = true;
        }
        else
            res += 1;
    }
    if (res == 0)
        return res;
    if (d)
        res -= 2;
    else
        res -= 1;

    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests;
    cin >> numTests;
    while (numTests--)
    {
        int x, y;
        cin >> x;
        cin >> y;
        cin.ignore();
        vector<vector<int>> mat;
        for (int i = 0; i < x; i++)
        {
            string line;
            getline(cin, line);
            istringstream iss(line);
            int num;
            vector<int> arr;
            while (iss >> num)
            {
                arr.push_back(num);
            }
            mat.push_back(arr);
        }
        cout << comp(mat) << endl;
    }
}