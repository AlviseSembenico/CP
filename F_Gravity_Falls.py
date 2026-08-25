t = int(input())

for _ in range(t):
    n = int(input())
    l = []
    mm = 0
    for i in range(n):
        ll = list(map(int, input().split()[1:]))
        mm = max(mm, len(ll))
        l.append(ll)

    res = []
    i = 1
    while len(res) < mm:
        x = min(l)
        res += x
        l = [i[len(x) :] for i in l if len(i) > len(x)]
    # print(res)

    print(" ".join(map(str, res)))
