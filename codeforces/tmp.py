t = int(input())
from collections import defaultdict


class DDict(defaultdict):

    def __setitem__(self, key, value):
        return super().__setitem__(str(key), value)

    def __getitem__(self, key):
        return super().__getitem__(str(key))


def comp(a, b):
    a1 = defaultdict(int)
    b1 = defaultdict(int)

    for i, (na, nb) in enumerate(zip(a, b)):
        a1[na] = i
        b1[nb] = i
    n = len(a)
    res = 0

    for i in range(n - 1, -1, -1):
        ai = a[i]
        bi = b[i]
        if a1[ai] != i:
            return i + 1
        if b1[bi] != i:
            return i + 1

        if a1[bi] > i + 1 or a1[bi] == i:
            return i + 1

        if b1[ai] > i + 1 or b1[ai] == i:
            return i + 1
    return 0


for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    print(comp(a, b))
