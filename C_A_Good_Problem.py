N = int(input())
from math import *


def f(n, l, r, k):
    if n % 2 == 1:
        return l
    low = l
    ml = int(2 ** (floor(log2(low) + 1)))
    # print(low, ml)
    if ml > r or n < 4:
        return -1
    if k >= n - 1:
        return ml
    return l


for _ in range(N):
    n, l, r, k = list(map(int, input().split(" ")))
    print(f(n, l, r, k))

# print(f(4, 6, 9, 2))
