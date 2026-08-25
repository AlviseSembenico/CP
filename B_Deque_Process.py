import sys
from collections import deque

input = sys.stdin.readline


def comp(a):
    first = a.popleft()
    q = a.popleft()
    res = ["L", "L"]
    up = q > first
    while len(a) >= 2:
        if up:
            if a[0] < q or a[-1] < q:
                if a[0] < q:
                    res.append("L")
                    q = a.popleft()
                else:
                    res.append("R")
                    q = a.pop()
                up = False
            else:
                if a[0] > a[-1]:
                    res.append("LR")
                    _ = a.popleft()
                    q = a.pop()
                    up = False
                else:
                    res.append("RL")
                    _ = a.pop()
                    q = a.popleft()
                    if len(a) >= 2:
                        up = a[0] < a[-1]
        else:
            if a[0] > q or a[-1] > q:
                if a[0] > q:
                    res.append("L")
                    q = a.popleft()
                else:
                    res.append("R")
                    q = a.pop()
                up = True
            else:
                if a[0] < a[-1]:
                    res.append("LR")
                    _ = a.popleft()
                    q = a.pop()
                    up = True
                else:
                    res.append("RL")
                    _ = a.pop()
                    q = a.popleft()
                    if len(a) >= 2:
                        up = a[0] < a[-1]
    if a:
        res.append("L")
    return "".join(res)


t = int(input())
for _ in range(t):
    n = int(input())
    p = deque(map(int, input().split()))
    print(comp(p))
