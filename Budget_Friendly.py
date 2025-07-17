from functools import cache

C, B = map(int, input().split())


hs = []
for _ in range(C):
    H = int(input())
    hh = []
    for _ in range(H):
        hh.append(list(map(float, input().split())))
    hs.append(hh)
    hs.sort(key=lambda x: x[0])

if sum([h[0][0] for h in hs]) > B:
    print(-1)
    exit()


@cache
def comp(i, b):
    if i >= len(hs):
        return 0
    res = -float("inf")
    for pr, val in hs[i]:
        if pr > b:
            continue
        res = max(res, val + comp(i + 1, b - pr))
    return res


print("{0:.2f}".format(comp(0, B)))
