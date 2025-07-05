from functools import cache

n, x = list(map(int, input().split()))
l = list(map(int, input().split()))
l.sort()
inf = float("inf")

import sys

sys.setrecursionlimit(10**8)


@cache
def main(x, i):
    if x == 0:
        return 1

    res = 0
    for j in range(i, n):
        if l[j] > x:
            return res
        res += main(x - l[j], j)
    return res


print(main(x, 0))
