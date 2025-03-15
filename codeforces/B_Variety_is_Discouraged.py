# import sys
# from collections import Counter, defaultdict


# def comp(l):
#     c = defaultdict(int)
#     for i in l:
#         c[i] += 1
#     unt = [k for k, v in c.items() if v > 1]
#     i = 0
#     best = 0
#     res = 0
#     for j, n in enumerate(l):
#         if n in unt:
#             i = j + 1
#             continue
#         if j - i + 1 >= best:
#             best = j - i + 1
#             res = (i, j)
#     return res


# def main():
#     n = int(sys.stdin.readline())
#     res = [0] * n
#     for i in range(n):
#         sys.stdin.readline()
#         l = [int(x) for x in sys.stdin.readline().split(" ")]
#         v = comp(l)
#         if isinstance(v, int):
#             res[i] = str(v)
#         else:
#             res[i] = f"{v[0] + 1} {v[1] + 1}"

#     print("\n".join(res))


# main()
import sys
from collections import defaultdict


def comp(l):
    c = defaultdict(int)
    for i in l:
        c[i] += 1
    # Using a set for faster membership checks (logic remains identical)
    unt = {k for k, v in c.items() if v > 1}
    i = 0
    best = 0
    res = 0
    for j, n in enumerate(l):
        if n in unt:
            i = j + 1
            continue
        if j - i + 1 >= best:
            best = j - i + 1
            res = [i, j]
    return res


def main():
    data = sys.stdin.read().splitlines()
    n = int(data[0])
    out = []
    line = 1
    for _ in range(n):
        # Skip the line with the count (not needed)
        line += 1
        l = list(map(int, data[line].split()))
        line += 1
        v = comp(l)
        if isinstance(v, int):
            out.append(str(v))
        else:
            out.append(f"{v[0] + 1} {v[1] + 1}")
    sys.stdout.write("\n".join(out))


if __name__ == "__main__":
    main()
