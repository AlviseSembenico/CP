
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<int> vint;
typedef vector<ll> vlong;

#define pb push_back
#define loop(a, b) for (int i = a; i < b; i++)
#define loop0(a) for (int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define icontains(v, x) (find(begin(v), end(v), x) != end(v))

int comp(string &s)
{
    unordered_map<int, vint> m;
    vint vals;
    int c = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
            c++;
        else
            c--;
        m[c].push_back(i);
        vals.push_back(c);
    }
    int res = s.size();
    int target = c;
    if (target == 0)
        return 0;
    for (int i = 0; i < s.size(); i++)
    {
        int v = vals[i];
        int prev = i == 0 ? 0 : vals[i - 1];
        int tt = prev + target;
        // int tt = v - target + copysign(1.0, -target);
        if (!m.contains(tt))
            continue;
        if (m[tt].back() < i)
            continue;
        int r = *lower_bound(all(m[tt]), i);
        res = min(res, r - i + 1);
    }

    return res == (int)s.size() ? -1 : res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    // #endif
    int t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        cout << comp(s) << endl;
    }
}