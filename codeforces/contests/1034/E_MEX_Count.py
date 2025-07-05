from collections import Counter, defaultdict


class DDict(defaultdict):

    def __setitem__(self, key, value):
        return super().__setitem__(str(key), value)

    def __getitem__(self, key):
        return super().__getitem__(str(key))


class Bict(dict):

    def __setitem__(self, key, value):
        return super().__setitem__(str(key), value)

    def __getitem__(self, key):
        return super().__getitem__(str(key))


t = int(input())
for _ in range(t):

    N = int(input())
    a = list(map(int, input().split()))
    # a.sort()

    c = DDict(int)
    for i in range(N):
        c[a[i]] += 1

    dr = DDict(int)

    last = -1
    rem = len(a)
    duplicate = 0
    keys = [int(k) for k in c.keys()]
    for n in sorted(keys):
        if n != last + 1:
            break
        v = c[n]
        rem -= v
        if n == 0:

            dr[v] += 1
            dr[v + rem + 1] -= 1
        else:
            dr[v] += 1
            dr[v + rem + 1 + duplicate] -= 1
        duplicate += v - 1
        last = n

    dr[1] += 1
    dr[duplicate + 1 + rem] -= 1
    res = [1]
    curr = 0
    for i in range(1, N + 1):
        curr += dr[i]
        res.append(curr)
    print(" ".join([str(i) for i in res]))
