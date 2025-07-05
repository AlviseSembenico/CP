# Write any import statements here
from collections import defaultdict
from typing import List


def getSecondsRequired(R: int, C: int, G: List[List[str]]) -> int:
    d = defaultdict(set)
    n, m = len(G), len(G[0])
    start = None
    for x in range(n):
        for y in range(m):
            v = G[x][y]
            if "a" <= v <= "z":
                d[v].add((x, y))
            if v == "S":
                start = (x, y)
    l = [start]
    dist = 0
    moves = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    while l:
        nl = []
        for x, y in l:
            v = G[x][y]
            G[x][y] = "#"

            if v == "E":
                return dist
            if "a" <= v <= "z":
                d[v].remove((x, y))
                nl += d[v]
                # for nx,ny in d[v]:

            for dx, dy in moves:
                nx = x + dx
                ny = y + dy
                if nx < 0 or nx >= n or ny < 0 or ny >= m:
                    continue
                v = G[nx][ny]
                if v == "#":
                    continue
                nl.append((nx, ny))
        l = nl
        dist += 1

    return -1
