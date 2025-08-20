
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
typedef vector<int> vint;
typedef vector<ll> vlong;

#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define contains(v, x) (find(begin(v), end(v), x) != end(v))

struct DSU
{
    vint e;
    void init(int N) { e = vint(N, -1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y)
    {
        x = get(x), y = get(y);
        if (x == y)
            return 0;
        if (e[x] > e[y])
            swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

int main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        int n, p;
        cin >> n >> p;
        vint v(n);
        for (int &i : v)
            cin >> i;
        DSU d;
        d.init(n);
        priority_queue<pii> pp;
        for (int i = 0; i < n; i++)
            pp.push(make_pair(-v[i], i));
        ll res = 0;
        while (!pp.empty() && -pp.top().first < p)
        {
            pii el = pp.top();
            pp.pop();
            int g = -el.first;
            int j = el.second + 1;
            while (j < n)
            {
                g = gcd(g, v[j]);
                if (g != -el.first || d.sameSet(el.second, j))
                    break;
                d.unite(el.second, j);
                res += g;
                j++;
            }
            g = -el.first;
            j = el.second - 1;
            while (j >= 0)
            {
                g = gcd(g, v[j]);
                if (g != -el.first || d.sameSet(el.second, j))
                    break;
                d.unite(el.second, j);
                res += g;
                j--;
            }
        }
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
            st.insert(d.get(i));

        res += p * (st.size() - 1);
        cout << res << endl;
    }
}