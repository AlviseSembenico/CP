import sys
from typing import List

sys.setrecursionlimit(10**7)


def getMaxVisitableWebpages(N: int, L: List[int]) -> int:
    reach = [-1] * (len(L) + 5)

    def f(n, stack):
        if n in stack:
            return 0
        if reach[n] != -1:
            return reach[n]
        res = 1

        stack.add(n)

        res += f(L[n - 1], stack)
        reach[n] = res
        return res

    for i in range(1, len(L) + 1):
        f(i, set())
    return max(reach)


N = int(input())
for _ in range(N):
    L = list(map(int, input().split()))
    result = getMaxVisitableWebpages(N, L)
    print(result)
