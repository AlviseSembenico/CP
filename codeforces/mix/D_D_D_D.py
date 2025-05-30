from collections import defaultdict


def comp(g, ls: list):
    ls.sort()
    distances = []
    inf = float("inf")
    for i in range(len(g) + 1):
        distances.append([inf, inf])

    def bfs():
        nodes = [1]
        dist = 0
        while nodes:
            nn = []
            for node in nodes:
                # tm = [i % 2 for i in distances[node]]
                tm = distances[node]
                if tm[dist % 2] != inf:
                    continue
                tm[dist % 2] = dist
                for n in g[node]:
                    nn.append(n)
            nodes = nn
            dist += 1

    bfs()
    lt = sum(ls)
    min_odd = float("inf")
    for l in ls:
        if l % 2 == 1:
            min_odd = l
            break

    lt2 = lt - min_odd
    if lt % 2 == 1:
        lt, lt2 = lt2, lt
    # lt is even, lt2 odd
    # print(g)
    # print(distances)
    res = [1]
    for node in list(range(2, len(g) + 1)):
        ns = distances[node]

        if len(ns) == 0:
            res.append(0)
            continue
        if len(ns) == 1:
            ns.add(float("inf"))

        a, b = ns
        if a % 2 == 1:
            a, b = b, a

        if lt >= a or lt2 >= b:
            res.append(1)
        else:
            res.append(0)

    return res


N = int(input())
for n in range(N):
    n, m, l = map(int, input().split())
    ls = list(map(int, input().split()))
    graph = defaultdict(set)
    for i in range(m):
        a, b = map(int, input().split())
        graph[a].add(b)
        graph[b].add(a)
    r = comp(graph, ls)
    print("".join(map(str, r)))
