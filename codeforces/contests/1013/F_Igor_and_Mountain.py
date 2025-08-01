from bisect import *
from math import *

mod = 998244353


def find_index_ge(arr, val):
    idx = bisect_left(arr, val)
    if idx < len(arr) and arr[idx] >= val:
        return idx
    return -1


def find_index_le(arr, val):
    idx = bisect_right(arr, val) - 1
    if idx >= 0 and arr[idx] <= val:
        return idx
    return -1


def prefix_sum(arr):
    ps = [0] * (len(arr) + 1)
    for i in range(len(arr)):
        ps[i + 1] = ps[i] + arr[i] % mod
    return ps


def comp2(n, m, d, mat):
    dp = [1] * len(mat[-1])
    R = floor(sqrt(d**2 - 1))
    for i in range(n - 2, -1, -1):
        vals = mat[i]
        prev_v = mat[i + 1]
        pf = prefix_sum(dp)
        for ii, ind in enumerate(prev_v):
            l = find_index_ge(prev_v, ind - d)
            r = find_index_le(prev_v, ind + d)
            dp[ii] = pf[r + 1] - pf[l]

        curr = [0] * len(vals)
        pf = prefix_sum(dp)
        for ii, v in enumerate(vals):
            target = v - R
            l = find_index_ge(prev_v, target)
            if l == -1:
                continue
            r = find_index_le(prev_v, v + R)
            curr[ii] = pf[r + 1] - pf[l] % mod

        dp = curr

    prev_v = mat[0]
    pf = prefix_sum(dp)
    res = 0
    for ii, ind in enumerate(prev_v):
        l = find_index_ge(prev_v, ind - d)
        r = find_index_le(prev_v, ind + d)
        res += pf[r + 1] - pf[l]
        res %= mod
    return res


def main():

    tests = int(input())

    for _ in range(tests):
        n, m, d = list(map(int, input().split(" ")))
        ma = []
        for i in range(n):
            l = list(map(lambda x: 1 if x == "X" else 0, input()))
            ll = []
            for i, j in enumerate(l):
                if j == 1:
                    ll.append(i)
            ma.append(ll)
        print(comp2(n, m, d, ma))


main()
