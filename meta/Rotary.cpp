#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

long long dp[3004][3004];

int modAbsDiff(int a1, int b1, int m)
{
    auto norm = [m](int x)
    { return ((x - 1) % m + m) % m; };
    int d = abs(norm(a1) - norm(b1));
    return min(d, m - d);
}

long long m(int i, vector<int> &c, int ot, int N)
{
    if (i >= c.size())
        return 0;

    if (ot >= 0)
        if (dp[i][ot] != -1)
            return dp[i][ot];
    int va = c[i - 1];
    int vb = ot >= 0 ? c[ot] : 1;
    int t = c[i];
    long long res = min(m(i + 1, c, ot, N) + modAbsDiff(va, t, N), m(i + 1, c, i - 1, N) + modAbsDiff(vb, t, N));
    if (ot >= 0)
        dp[i][ot] = res;
    return res;
}

long long getMinCodeEntryTime(int N, int M, vector<int> C)
{
    // Write your code here
    memset(dp, -1, sizeof(dp));
    return m(1, C, -1, N) + modAbsDiff(1, C[0], N);
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> C(M);
    for (int i = 0; i < M; i++)
        cin >> C[i];
    cout << getMinCodeEntryTime(N, M, C);
}