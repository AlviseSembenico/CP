t = int(input())
from math import *


def comp(a, b, k):
    if max(a, b) <= k:
        return 1

    if gcd(a, b) == 1 or max(a, b) / gcd(a, b) > k:
        return 2
    return 1


for _ in range(t):
    a, b, k = map(int, input().split())
    print(comp(a, b, k))
