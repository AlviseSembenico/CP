#include <bits/stdc++.h>

using namespace std;
const int mxN = 200002;
vector<int> factorize[mxN];

void pre()
{
    for (int i = 2; i < mxN; i++)
    {
        for (int j = i; j < mxN; j += i)
        {
            factorize[j].push_back(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    pre();
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> l(n);
        for (int i = 0; i < n; i++)
            cin >> l[i];
        vector<int> res;
        int ans = 0;
        vector<int> buckets(mxN, 0);
        vector<int> check;
        vector<bool> pres(mxN, false);
        for (int i = 0; i < n; i++)
        {
            int val = l[i];
            auto &fs = factorize[val];
            for (int f : fs)
            {
                buckets[f]++;
                if (buckets[f] != i + 1)
                {
                    ans = max(ans, buckets[f]);
                }
                else
                {
                    if (!pres[f])
                    {
                        check.push_back(f);
                        pres[f] = true;
                    }
                }
            }
            vector<int> nn;
            for (int v : check)
            {
                if (buckets[v] != i + 1)
                {
                    ans = max(ans, buckets[v]);
                    pres[v] = false;
                }
                else
                {
                    nn.push_back(v);
                }
            }
            check = move(nn);
            res.push_back(ans);
        }
        for (int i = 0; i < res.size(); i++)
        {
            if (i)
                cout << " ";
            cout << res[i];
        }
        cout << "\n";
    }
}
