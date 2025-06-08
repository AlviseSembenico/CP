#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << " ";
    }
    return os;
}

inline ll power(ll x, ll exp, ll mod)
{
    ll ans = 1;
    while (exp > 0)
    {
        if (exp & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        exp /= 2;
    }
    return ans;
}

vector<ll> comp(vector<ll> &p, vector<ll> &q)
{
    ll mod = 998244353;
    vector<ll> res = {};

    ll mq = 0;
    ll mp = 0;
    int iq = 0;
    int ip = 0;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] > mp)
        {
            mp = p[i];
            ip = i;
        }
        if (q[i] > mq)
        {
            mq = q[i];
            iq = i;
        }
        if (mp == mq)
        {
            int y = max(q[i - ip], p[i - iq]);
            res.push_back((power(2LL, mp, mod) + power(2LL, y, mod)) % mod);
        }
        else
        {
            if (mp > mq)
                res.push_back((power(2LL, mp, mod) + power(2LL, q[i - ip], mod)) % mod);
            else
                res.push_back((power(2LL, mq, mod) + power(2LL, p[i - iq], mod)) % mod);
        }
    }
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
        int size;
        cin >> size;
        cin.ignore();
        vector<ll> ps(size);

        for (int i = 0; i < size; i++)
            cin >> ps[i];

        vector<ll> qs(size);

        for (int i = 0; i < size; i++)
            cin >> qs[i];
        cout << comp(ps, qs) << "\n";
    }
}