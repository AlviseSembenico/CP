from collections import defaultdict
from copy import deepcopy

t = int(input())


def comp(l):
    d = defaultdict(int)
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
    l = list(map(int, input().split()))
    print(comp(l))
