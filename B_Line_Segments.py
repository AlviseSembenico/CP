N = int(input())


import math


def euclidean_distance(x1, y1, x2, y2):
    return math.hypot(x2 - x1, y2 - y1)


def f(px, py, qx, qy, moves):

    d = euclidean_distance(px, py, qx, qy)
    S = sum(moves)
    M = max(moves)
    L = max(0, 2 * M - S)
    return "Yes" if L <= d <= S else "No"


for _ in range(N):
    n = int(input())
    a, b, x, y = list(map(int, input().split(" ")))
    moves = list(map(int, input().split(" ")))
    print(f(a, b, x, y, moves))
