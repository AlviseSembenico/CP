t = int(input())


def comp(c, a):

    big_c = [i for i in a if i > c]
    small_c = [i for i in a if i <= c]
    time = 1
    res = len(big_c)
    small_c.sort()

    while small_c:
        while small_c and small_c[-1] * (1 << (time - 1)) > c:
            res += 1
            # print("too big", small_c[-1], time, res)
            small_c.pop()
        if small_c:
            # print("taking", small_c[-1], time, res)
            small_c.pop()
        time += 1
    return res


for _ in range(t):
    n, c = map(int, input().split())
    a = list(map(int, input().split()))
    print(comp(c, a))
