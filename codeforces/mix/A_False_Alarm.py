n = int(input())


def comp(ls, x):
    i = 0
    while i < len(ls):
        d = ls[i]
        if d == 0:
            i += 1
            continue
        if x < 0:
            return "NO"
        i += x
        x = -1
    return "YES"


for _ in range(n):
    n, x = map(int, input().split())
    ls = list(map(int, input().split()))
    print(comp(ls, x))
