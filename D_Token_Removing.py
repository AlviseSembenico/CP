N = int(input())
from functools import cache


@cache
def nchoosekmod(n, k, mod):
    if k > n:
        return 0
    if k == 0 or k == n:
        return 1
    if k > n // 2:
        k = n - k
    res = 1
    for i in range(k):
        res = (res * (n - i)) % mod
        res = (res * pow(i + 1, mod - 2, mod)) % mod
    return res


def f(n, m):

    def main(i, n0):
        if i == 1:
            return 1
        if n0 == 0 or n0 == i:
            return 1
        res = main(i - 1, n0 - 1) + main(i - 1, n0)
        for v in range(1, i):
            for nn in range(0, i + 1):
                res += nn * main(v, nn)
        return res

    res = 0
    for i in range(n + 1):
        res += main(n, i)
    return res


for _ in range(N):
    n, m = list(map(int, input().split(" ")))
    print(f(n, m))
