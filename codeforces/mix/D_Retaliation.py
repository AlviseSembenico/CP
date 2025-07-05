import math
from functools import cache

t = int(input())


def comp(l):
    n = len(l)
    if n == 1:
        return "YES"
    x1 = l[0]
    x2 = l[1]

    a = (n * x2 - (n - 1) * x1) / (n + 1)
    b = (2 * x1 - x2) / (n + 1)
    if not (a.is_integer() and b.is_integer() and a >= 0 and b >= 0):
        return "NO"
    for i, num in enumerate(l):
        if a * (i + 1) + b * (n - i) != num:
            return "NO"
    return "YES"


for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    print(comp(l))
