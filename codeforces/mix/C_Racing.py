from functools import cache

t = int(input())


# def comp(arr, obs):
#     res = []
#     pos = 0
#     last_pos = []
#     h = 0
#     i = 0
#     max_pos =0
#     for d, (l, r) in zip(arr, obs):
#         if d == 0:
#             continue
#         if d == 1:
#             h += 1
#         if d == -1:
#             last_pos.append(i)

#         if h<l:
#             for _ in range(l-h):


# i += 1
#


def comp(arr, obs):
    h = 0
    l, r = 0, 0
    lr = []
    rr = []
    for d, (li, ri) in zip(arr, obs):
        if d == 0:
            ...
        if d == 1:
            l += 1
            r += 1
        if d == -1:
            r += 1
        lr.append(max(l, li))
        rr.append(min(r, ri))
        print(l, r)
        if r < l or r < ri or l > li:
            return None
    # print(lr, arr)
    res = []
    h = lr[-1]
    for i in range(len(arr) - 1, -1, -1):
        if arr[i] != -1:
            res.append(arr[i])
            continue
        if lr[i] <= h <= rr[i]:
            res.append(0)
        else:
            res.append(1)
            h -= 1
    return res[::-1]


def comp(arr, obs):
    n = len(arr)
    lr = [0] * n
    rr = [0] * n
    l = r = 0

    for i, (d, (li, ri)) in enumerate(zip(arr, obs)):
        if d == 0:
            nl, nr = l, r
        elif d == 1:
            nl, nr = l + 1, r + 1
        else:  # d == -1
            nl, nr = l, r + 1

        nl = max(nl, li)
        nr = min(nr, ri)
        # print(nl, nr)
        if nl > nr:
            return

        lr[i], rr[i] = nl, nr
        l, r = nl, nr

    res = [0] * n
    h = rr[-1]
    for i in range(n - 1, -1, -1):
        if arr[i] != -1:
            res[i] = arr[i]
            h -= arr[i]
        else:
            prevL = lr[i - 1] if i > 0 else 0
            prevR = rr[i - 1] if i > 0 else 0
            if prevL <= h <= prevR:
                res[i] = 0
            else:
                res[i] = 1
                h -= 1

    return res


for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    obs = []
    for i in range(n):
        obs.append(list(map(int, input().split())))

    r = comp(arr, obs)
    if r is None:
        print("-1")
    else:
        print(" ".join(map(str, r)))
