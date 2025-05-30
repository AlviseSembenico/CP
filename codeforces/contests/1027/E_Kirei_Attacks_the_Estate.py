import sys
from collections import defaultdict
from functools import cache

N = int(input())

sys.setrecursionlimit(10**8)

from collections import deque


def comp(n, g, d):
    if n == 1:
        return str(d[0])

    dp = [0] * n
    # pairs[i] = (max_val up to i, min_val up to i)
    pairs = [None] * (n + 1)
    pairs[1] = (d[0], 0)
    dp[0] = d[0]

    parent = [0] * (n + 1)
    q = deque([1])
    while q:
        u = q.popleft()
        p_max, p_min = pairs[u]
        for v in g[u]:
            if v == parent[u]:
                continue
            parent[v] = u
            val = d[v - 1]
            max_v = max(val, val - p_min)
            min_v = min(val, val - p_max)
            pairs[v] = (max_v, min_v)
            dp[v - 1] = max_v
            q.append(v)

    return " ".join(map(str, dp))


for i in range(N):
    n = int(input())
    d = list(map(int, input().split()))
    g = defaultdict(list)
    for _ in range(n - 1):
        a, b = map(int, input().split())
        g[b].append(a)
        g[a].append(b)
    print(comp(n, g, d))
