from collections import defaultdict
from functools import cache
from math import gcd

t = int(input())


class DDict(defaultdict):

    def __setitem__(self, key, value):
        return super().__setitem__(str(key), value)

    def __getitem__(self, key):
        return super().__getitem__(str(key))


factorize = defaultdict(list)
mxN = int(2e5 + 2)


def pre():
    for i in range(2, mxN):
        for j in range(i, mxN, i):
            factorize[j].append(i)


pre()
for _ in range(t):
    _ = input()
    l = list(map(int, input().split()))
    res = []
    ans = 0
    buckets = DDict(int)
    check = set()
    for i, val in enumerate(l):
        fs = factorize[val]
        for f in fs:
            buckets[f] += 1
            if buckets[f] != i + 1:
                ans = max(ans, buckets[f])
            else:
                check.add(str(f))

        nn = set()
        for v in check:
            v = int(v)
            if buckets[v] != i + 1:
                ans = max(ans, buckets[v])
            else:
                nn.add(str(v))
        check = nn
        res.append(ans)

    print(" ".join(map(str, res)))
