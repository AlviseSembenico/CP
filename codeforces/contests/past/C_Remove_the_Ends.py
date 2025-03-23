def comp(l):
    a = [0] * (len(l) + 1)
    b = [0] * (len(l) + 1)
    n = len(l)
    for i in range(n):
        a[i + 1] = a[i] + max(0, l[i])
    for i in range(n - 1, -1, -1):
        b[i] = b[i + 1] + max(0, -l[i])
    r = 0
    # print(a, b)
    for ai, bi in zip(a, b):
        r = max(r, ai + bi)
    return r


def main():
    n = int(input())
    for i in range(n):
        input()
        l = [int(x) for x in input().split(" ")]
        print(comp(l))


main()
