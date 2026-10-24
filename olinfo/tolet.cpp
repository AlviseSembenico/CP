
#include <vector>
#include <iostream>
#include <algorithm>

#define all(x) x.begin(), x.end()
using namespace std;
typedef vector<int> vint;

typedef long long int ll;

ll N;
vector<int> V;
vector<ll> PS;
ll n;
void acquista(int N, vector<int> P)
{
    ::N = N;
    ::V = P;
    sort(all(V));
    ll s = 0;
    for (ll v : V)
    {
        s += v;
        PS.push_back(s);
    }
}

bool check(ll K, ll T, ll target)
{
    if (target > V.back())
        return true;
    if (V.back() - target > T)
        return false;
    auto it = upper_bound(all(V), target);
    ll i, val;
    if (it != V.begin())
    {
        it--;
        i = it - V.begin();
    }
    else
    {
        i = -1;
    }
    ll above = PS.back() - (i >= 0 ? PS[i] : 0);
    ll needed = above - target * (N - 1 - i);
    if (needed > K * T)
        return false;
    return true;
}

int ispeziona(int K, int T)
{
    ll i = 0;
    ll j = V.back(); // Search space
    while (i < j - 1)
    {
        ll mid = i + (j - i) / 2;
        if (check(K, T, mid))
            j = mid;
        else
            i = mid;
    }
    if (check(K, T, i))
        return i;
    return j;
}

// SAMPLE GRADER, DO NOT MODIFY

#ifndef EVAL

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N, Q;
    cin >> N >> Q;

    vector<int> P(N);
    for (auto &x : P)
        cin >> x;

    vector<pair<int, int>> Qs(Q);
    for (auto &[k, t] : Qs)
    {
        cin >> k >> t;
    }

    acquista(N, P);

    for (auto [k, t] : Qs)
    {
        cout << ispeziona(k, t) << "\n";
    }
}

#endif /* EVAL */
