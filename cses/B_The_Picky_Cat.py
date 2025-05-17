from math import *


def c(l):
    size = len(l)
    target = abs(l[0])
    l.sort()
    ind = l.index(target)
    if ind > floor(size / 2):
        return "NO"
    return "YES"


n = int(input())


for _ in range(n):
    size = int(input())
    l = list(map(lambda x: abs(int(x)), input().split()))
    print(c(l))
