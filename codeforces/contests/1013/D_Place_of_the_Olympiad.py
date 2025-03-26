from math import *


def comp(n, m, k):
    dpr = ceil(k / n)
    # print(dpr)
    blocks = m - dpr + 1
    return ceil(dpr / blocks)


def main():

    tests = int(input())

    for _ in range(tests):
        n, m, k = list(map(int, input().split(" ")))

        print(comp(n, m, k))


main()
