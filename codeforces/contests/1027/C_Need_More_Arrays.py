n = int(input())


def comp(l):
    res = 0
    prev = -1
    for i in l:
        if i > prev + 1:
            res += 1
            prev = i

    return res


for i in range(n):
    n = int(input())

    l = list(map(int, input().split()))
    print(comp(l))
