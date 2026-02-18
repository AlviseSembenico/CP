#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0

#if DEBUG
#define HAS_EXTRA 1
#include "./codeforces/debug.hpp"
#endif

#ifndef ONLINE_JUDGE
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}
#else
// If not debugging, define deb as empty
#define deb(...)
#endif
#define pb push_back
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<int> vint;
typedef vector<ll> vlong;

using Grid2D = vector<vector<ll>>;
using Grid3D = vector<Grid2D>;
auto make_3d(int d1, int d2, int d3, ll val = 0)
{
    return Grid3D(d1, Grid2D(d2, vector<ll>(d3, val)));
}
auto make_2d(int d1, int d2, ll val = 0)
{
    return Grid2D(d1, vector<ll>(d2, val));
}
#define pb push_back
#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef CINPUT
    freopen("input.txt", "r", stdin);
#endif
    int N, M;
    cin >> N >> M;
    vector<vint> score(N, vint(M));
    vector<vint> color(N, vint(M));
    loop0(N)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> score[i][j];
        }
    }
    int mc = 1;
    loop0(N)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> color[i][j];

            mc = max(mc, color[i][j]);
        }
    }
    ll res = LONG_LONG_MIN;
    // Preallocate all arrays outside loops
    Grid2D dp = make_2d(mc + 5, M, LONG_LONG_MIN);
    Grid2D ndp = make_2d(mc + 5, M, LONG_LONG_MIN);
    vlong left(mc + 5, LONG_LONG_MIN);

    for (int i = 0; i < N; i++)
    {
        fill(left.begin(), left.end(), LONG_LONG_MIN);
        for (int c = 1; c <= mc; c++)
        {
            fill(ndp[c].begin(), ndp[c].end(), LONG_LONG_MIN);
        }

        for (int j = 0; j < M; j++)
        {
            int cell_c = color[i][j];
            int v = score[i][j];

            for (int c = 1; c <= mc; c++)
            {
                ll best_pre = max(left[c], dp[c][j]);
                if (best_pre == LONG_LONG_MIN && c != cell_c)
                    continue;
                if (c == cell_c)
                    best_pre = max(best_pre, 0LL);

                best_pre += v;
                left[c] = best_pre;
                ndp[c][j] = best_pre;

                if (c == cell_c)
                    res = max(res, best_pre);
            }
        }
        swap(dp, ndp);
    }
    cout << res;
}