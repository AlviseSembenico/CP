import math
import sys
from itertools import combinations


def bounding_rectangle(coords, ignore=-1):
    xs = [x for i, (x, y) in enumerate(coords) if i != ignore]
    ys = [y for i, (x, y) in enumerate(coords) if i != ignore]
    min_x, max_x = min(xs), max(xs)
    min_y, max_y = min(ys), max(ys)
    dx, dy = max_y - min_y + 1, max_x - min_x + 1
    return dx, dy, dx * dy == len(coords)


def main():
    it = iter(sys.stdin.read().split())
    t = int(next(it))
    out = []
    for _ in range(t):
        n = int(next(it))
        coords = [(int(next(it)), int(next(it))) for _ in range(n)]
        if n == 1:
            out.append("1")
            continue
        top = min(range(n), key=lambda i: coords[i][0])
        bottom = max(range(n), key=lambda i: coords[i][0])
        left = min(range(n), key=lambda i: coords[i][1])
        right = max(range(n), key=lambda i: coords[i][1])
        idx = {top, bottom, left, right}
        core = [c for i, c in enumerate(coords) if i not in idx]
        cand = [coords[i] for i in idx]
        best = math.inf
        for rem in combinations(cand, len(cand) - 1):
            cands = core + list(rem)
            dx, dy, packed = bounding_rectangle(cands)
            cost = (
                dx * dy if not packed else (dx * (dy + 1) if dx < dy else (dx + 1) * dy)
            )
            best = min(best, cost)
        out.append(str(best))
    sys.stdout.write("\n".join(out))


if __name__ == "__main__":
    main()
