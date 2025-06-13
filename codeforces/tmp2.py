from collections import defaultdict
from copy import deepcopy

t = int(input())


class DDict(defaultdict):

    def __setitem__(self, key, value):
        return super().__setitem__(str(key), value)

    def __getitem__(self, key):
        return super().__getitem__(str(key))


def comp(l):
    d = DDict(int)
    for i, n in enumerate(l):
        d[n] = i

    res = 0

    taken = set()
    to_take = set()
    curr = set()
    for i, n in enumerate(l):
        if d[n] > i:
            curr.add(n)
            if n in to_take:
                to_take.remove(n)
        else:
            return res + 1

        if len(to_take) == 0:
            res += 1
            taken = taken.union(curr)
            to_take = deepcopy(taken)
    return res


for _ in range(t):
    n = int(input())
    l = list(input().split())
    print(comp(l))
