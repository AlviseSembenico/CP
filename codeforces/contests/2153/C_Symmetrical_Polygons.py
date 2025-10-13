import sys
from bisect import bisect_left, bisect_right
from collections import defaultdict

# sys.stdin = open("input2.txt", "r")
t = int(input())


class DDict(defaultdict):

    def __setitem__(self, key, value):
        return super().__setitem__(str(key), value)

    def __getitem__(self, key):
        return super().__getitem__(str(key))


def get_singles(l, R):
    for i in range(len(l) - 2, -1, -1):
        v1 = l[i]
        v2 = l[i + 1]
        if v2 - v1 < R:
            return v2 + v1, i == 0
    return -1, True


for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))

    c = DDict(int)
    for i in l:
        c[i] += 1

    res = 0

    side = 0
    for k, v in c.items():
        k = int(k)
        v = v - (v % 2)
        side += v
        res += k * v

    odds = [0]
    for k, v in c.items():
        k = int(k)
        if v % 2 != 0:
            odds.append(k)

    if len(odds) > 1:
        odds.sort()
        vv, add_side = get_singles(odds, res)
        if vv > 0:
            res += vv
            side += 1 + (not add_side)
    if side < 3:
        print(0)
        continue
    else:
        print(res)
