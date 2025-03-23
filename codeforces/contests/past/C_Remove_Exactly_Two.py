from collections import defaultdict


def comp(g, left):
    if len(g) == 0:
        return 0

    val = -1
    cands = []
    for k, v in g.items():
        if len(v) == val:
            cands.append(k)
        if len(v) > val:
            val = len(v)
            cands = [k]

    if left == 0:
        return val
    if len(cands) >= 3:
        return 2 * val - 1
    if len(cands) == 2:
        if cands[0] in g[cands[1]]:
            return 2 * val - 2
        return 2 * val - 1
    r = cands[0]
    for node in g[r]:
        g[node].remove(r)
    del g[r]
    return val + comp(g, 0) - 1


def main():
    n = int(input())
    for i in range(n):
        lines = int(input())
        g = defaultdict(set)
        for i in range(lines - 1):
            f, t = (int(x) for x in input().split(" "))
            g[f].add(t)
            g[t].add(f)

        print(comp(g, 1))


main()
