// https://oj.uz/problem/view/BOI13_tracks

#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "./codeforces/debug.hpp"
#endif

typedef long long int ll;
typedef vector<int> vint;
typedef vector<ll> vlong;

#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))

inline void print(const vector<pair<int, int>> &v)
{
    for (auto &[x, y] : v)
        cout << '(' << x << ',' << y << ") ";
    cout << '\n'
         << flush;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // eat up to and including '\n'
    vector<string> g(n);
    loop0(n)
    {
        getline(cin, g[i]);
    }

    vector<vint> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int c = 0;
    vector<pair<int, int>> pos = {make_pair(0, 0)};
    char curr = g[0][0];
    while (!pos.empty())
    {
        vector<pair<int, int>> p(pos.begin(), pos.end());
        vector<pair<int, int>> newpos;
        pos.clear();
        // BFS from p
        while (!p.empty())
        {
            vector<pair<int, int>> np;
            for (auto pr : p)
            {
                loop0(4)
                {
                    int x = pr.first + moves[i][0];
                    int y = pr.second + moves[i][1];
                    if (x < 0 || x >= g.size() || y < 0 || y >= g[0].size())
                        continue;
                    char val = g[x][y];
                    if (val != curr && val != '.')
                    {
                        g[x][y] = '.';
                        newpos.push_back(make_pair(x, y));
                    }
                    if (val == curr)
                    {
                        g[x][y] = '.';
                        np.push_back(make_pair(x, y));
                    }
                }
            }

            p.swap(np);
        }
        pos.swap(newpos);
        c++;
        curr = curr == 'F' ? 'R' : 'F';
    }
    cout << c;
    return 0;
}