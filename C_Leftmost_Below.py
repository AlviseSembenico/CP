t = int(input())


def comp(a):
    # m = min(a)
    # a = [i - m for i in a]
    m = a[0]
    for i in a[1:]:
        if i > 2 * m - 1:
            return "NO"
        m = min(m, i)
    return "YES"


for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    print(comp(a))
