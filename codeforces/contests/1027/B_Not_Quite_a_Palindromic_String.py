from collections import Counter

n = int(input())


def comp(n, k, s):
    c = Counter(s)
    reman = n - 2 * k

    z = c["0"]
    o = c["1"]

    z -= reman // 2
    o -= reman // 2

    if z < 0 or o < 0:
        return "NO"

    if z % 2 == 0 and o % 2 == 0:
        return "YES"
    return "NO"


for i in range(n):
    n, k = map(int, input().split())
    s = input()
    print(comp(n, k, s))
