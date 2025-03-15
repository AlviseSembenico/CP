import random
import sys
import time
from functools import cache

import numpy as np

t = np.random.randint(0, int(1e5), (100, int(1e4)))
sys.setrecursionlimit(int(1e7))


def comp(l):
    res = 0
    i = 0
    while i < len(l) and l[i] > 0:
        res += l[i]
        i += 1
    j = len(l)
    while j > 0 and l[j - 1] < 0:
        res -= l[j - 1]
        j -= 1
    l = l[i:j]

    @cache
    def main2(i, j):
        if i == j - 1:
            return abs(l[i])
        res = 0
        for ind in range(i, j):
            n = l[ind]
            if n > 0:
                val = main2(ind + 1, j)
            else:
                val = main2(i, ind)
            val += abs(n)
            res = max(res, val)

        return res

    if len(l) == 0:
        return res
    return res + main2(0, len(l))


start_time = time.time()
for row in t:
    comp(row)
print("--- comp %s seconds ---" % (time.time() - start_time))


start_time = time.time()
for row in t:
    main2(row)
print("--- %s seconds ---" % (time.time() - start_time))
