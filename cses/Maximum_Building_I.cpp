

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
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<int> vint;
typedef vector<ll> vlong;

#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))

int numSubmat(vector<vector<bool>> &mat)
{
    int m = mat[0].size();
    int n = mat.size();
    vint heights(m + 1, 0);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            heights[j] = (mat[i][j] == 0) ? 0 : heights[j] + 1;
        stack<vint> st;
        st.push({-1, -1});
        for (int i = 0; i <= m; i++)
        {
            int h = heights[i];
            while (st.top()[1] >= h)
            {
                auto t = st.top();
                st.pop();
                int width = i - st.top()[0] - 1; // use new top after pop
                res = max(res, t[1] * width);
            }
            st.push({i, h});
        }
    }
    return res;
}

void print(const vector<vector<bool>> &v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        for (size_t j = 0; j < v[i].size(); ++j)
        {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> v(n, vector<bool>(m));
    loop0(n)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            v[i][j] = c == '.';
        }
    }

    // print(v);
    cout << numSubmat(v) << endl;

    return 0;
}