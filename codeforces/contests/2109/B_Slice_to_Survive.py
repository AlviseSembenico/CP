from math import ceil, log2


def solve(a, b):
    return ceil(log2(a)) + ceil(log2(b))


def comp(n, m, a, b):
    return min(solve(a, m), solve(n - a + 1, m), solve(n, b), solve(n, m - b + 1)) + 1


n = int(input())

for i in range(n):
    n, m, a, b = map(int, input().split())
    print(comp(n, m, a, b))
