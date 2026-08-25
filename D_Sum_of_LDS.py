t = int(input())


def comp(a):
    n = len(a)
    dp = [(1, 1)] * n
    # if a[1] < a[0]:
    #     dp[1] = (3, 2)

    for i in range(1, n):
        v = a[i]

        c, n = dp[i - 1]
        if a[i - 1] > v:
            dp[i] = (c + n + 1, n + 1)
        else:
            dp[i] = (c + 1, n + 1)
    # print(dp)
    return sum((d[0] for d in dp))


for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    print(comp(a))
