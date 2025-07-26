from bisect import *
from math import *


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
    mod = 998244353
    ps = [0] * (len(arr) + 1)
    for i in range(len(arr)):
        ps[i + 1] = ps[i] + arr[i] % mod
    return ps


def comp2(n, m, d, mat):
    mod = 998244353
    dp = [1] * len(mat[-1])
    R = isqrt(d**2 - 1)
    for i in range(n - 2, -1, -1):
        vals = mat[i]
        prev_v = mat[i + 1]

        old_dp = dp[:]
        dp = [0] * len(prev_v)
        l = r = 0
        window = 0
        for ii, ind in enumerate(prev_v):
            while r < len(prev_v) and prev_v[r] <= ind + d:
                window = (window + old_dp[r]) % mod
                r += 1
            while l < r and prev_v[l] < ind - d:
                window = (window - old_dp[l]) % mod
                l += 1
            dp[ii] = window

        curr = [0] * len(vals)
        l, r = 0, 0
        window = 0
        for ii, v in enumerate(vals):
            while r < len(prev_v) and prev_v[r] <= v + R:
                window = (window + dp[r]) % mod
                r += 1
            # shrink l so prev_v[l] < v - R
            while l < r and prev_v[l] < v - R:
                window = (window - dp[l]) % mod
                l += 1
            curr[ii] = window

        dp = curr

    prev_v = mat[0]
    res = 0
    l = r = 0
    window = 0
    for ii, ind in enumerate(prev_v):
        while r < len(prev_v) and prev_v[r] <= ind + d:
            window = (window + dp[r]) % mod
            r += 1
        while l < r and prev_v[l] < ind - d:
            window = (window - dp[l]) % mod
            l += 1
        res += window
        res %= mod

    return res


def main():

    tests = int(input())

    for _ in range(tests):
        n, m, d = list(map(int, input().split(" ")))
        ma = []
        for i in range(n):
            l = sys.stdin.readline()
            ll = []
            for i, j in enumerate(l):
                if j == "X":
                    ll.append(i)
            ma.append(ll)
        print(comp2(n, m, d, ma))


main()
