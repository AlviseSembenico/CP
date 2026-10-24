
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
    PS.assign(N + 1, 0);
    for (int k = 0; k < N; k++)
        PS[k + 1] = PS[k] + V[k];
}

l cost(int i)
{
    return PS[N] - PS[i] - (N - i) * V[i];
}

ll solve(ll B, int i)
{
    ll above = PS[N] - PS[i];
    if (above <= B)
        return 0;
    return (above - B + (N - i) - 1) / (N - i);
}

int ispeziona(int K, int T)
{
    if (K == 0)
        return V.back();
    if (K >= N)
        return max(0LL, (ll)V.back() - T);
    ll B = (ll)K * T;
    ll i = -1;
    ll j = N - 1;
    while (i < j - 1)
    {
        ll mid = i + (j - i) / 2;
        if (cost(mid) <= B)
            j = mid;
        else
            i = mid;
    }
    return max(solve(B, j), (ll)V.back() - T);
}

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
