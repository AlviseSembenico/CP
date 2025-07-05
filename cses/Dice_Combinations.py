import sys
from functools import cache

n = int(input())
sys.setrecursionlimit(10**8)


@cache
def main(x):
    # print(x)
    if x < 0:
        return 0
    if x == 1 or x == 0:
        return 1
    res = 0
    for i in range(1, min(7, x + 1)):
        res += main(x - i)
    return res


print(main(n))
