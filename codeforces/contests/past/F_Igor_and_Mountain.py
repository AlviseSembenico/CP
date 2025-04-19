import sys
from collections import defaultdict
from functools import cache
from math import *

sys.setrecursionlimit(1 << 25)
mod = 998244353


def euc(x, y, x2, y2):
    return hypot(x - x2, y - y2)


def comp(n, m, d, mat):
    g = defaultdict(list)
    for i in range(n - 1, -1, -1):
        for j in range(m):
            if mat[i][j] == 0:
                continue
            conn = []
            m1 = j - 1
            while m1 >= 0 and abs(j - m1) <= d:
                if mat[i][m1] == 1:
                    conn.append((i, m1))
                m1 -= 1

            m1 = j + 1
            while m1 < m and abs(j - m1) <= d:
                if mat[i][m1] == 1:
                    conn.append((i, m1))
                m1 += 1
            if i == 0:
                conn.append((-1, j))
            else:
                for j2 in range(m):
                    if mat[i - 1][j2] == 0:
                        continue
                    if euc(i, j, i - 1, j2) <= d:
                        conn.append((i - 1, j2))
            g[(i, j)] = conn

    @cache
    def dfs(i, j, level):
        if i < 0:
            return 1
        if (i, j) not in g:
            return 0
        res = 0
        for x, y in g[(i, j)]:
            if level and x == i:
                continue
            res += dfs(x, y, x == i) % 998244353
        return res % 998244353

    res = 0
    for i in range(m):
        if mat[n - 1][i] == 1:
            res += dfs(n - 1, i, 0)
    return res


def main():

    tests = int(input())

    for _ in range(tests):
        n, m, d = list(map(int, input().split(" ")))
        ma = []
        for i in range(n):
            l = list(map(lambda x: 1 if x == "X" else 0, input()))
            ma.append(l)
        print(comp(n, m, d, ma))


main()
