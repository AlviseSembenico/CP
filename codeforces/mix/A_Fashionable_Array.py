n = int(input())


def r(l):
    a = l[0]
    i = len(l) - 1
    while i >= 0:
        if abs(l[i] - a) % 2 == 0:
            return len(l) - i - 1
        i -= 1
    return len(l)


def comp(l):
    l.sort()
    return min(r(l), r(l[::-1]))


for i in range(n):
    size = int(input())
    arr = list(map(int, input().split()))
    print(comp(arr))
