import sys

sys.setrecursionlimit(1000)


def comp(size):
    if size == 1:
        return [[0]], False
    if size == 2:
        return [[0, 1], [2, 3]], True
    r, right = comp(size - 1)
    max_prev = (size - 1) ** 2 - 1
    if right:
        r.insert(0, list(range(max_prev + 1, max_prev + size)))
        point = max_prev + size
        for i in range(0, size - 1):
            r[i + 1].insert(0, point + i)
        r[0].insert(0, point + size - 1)
    else:
        for i in range(0, size - 1):
            r[i].append(max_prev + i + 1)
        r.append(list(range(max_prev + size, max_prev + 2 * size)))
    return r, not right


n = int(input())
for _ in range(n):
    size = int(input())
    res, _ = comp(size)
    for l in res:
        print(" ".join(map(str, l)))
