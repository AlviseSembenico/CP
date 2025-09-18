t = int(input())


def solve(a, b):
    a.sort()
    b.sort(reverse=True)
    # print(a, b)
    res = 0
    while b:
        k = b[-1]
        # print(k)
        b.pop()
        if k > len(a):
            res += sum(a)
            a = []
            break
        for _ in range(k - 1):
            res += a[-1]
            a.pop()
        a.pop()
    #     print(a, res, b)
    # print(a, res)
    res += sum(a)
    return res


for _ in range(t):
    n, k = list(map(int, input().split(" ")))
    a = list(map(int, input().split(" ")))
    b = list(map(int, input().split(" ")))
    print(solve(a, b))
