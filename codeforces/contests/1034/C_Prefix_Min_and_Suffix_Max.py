t = int(input())
for _ in range(t):
    N = int(input())
    a = list(map(int, input().split()))
    # higher min on left or higher max on right
    mi = [a[0]]
    for n in a[1:]:
        mi.append(min(mi[-1], n))
    ma = [a[-1]]
    for n in a[-2::-1]:
        ma.append(max(ma[-1], n))
    ma.reverse()
    # print(mi, ma, N)
    res = ""
    totmi = min(a)
    totma = max(a)
    for i in range(len(a)):
        n = a[i]
        if n == totmi or n == totma:
            res += "1"
            continue

        if i == 0:
            if n <= ma[i + 1]:
                res += "1"
            else:
                res += "0"
            continue
        if i == N - 1:
            if n >= mi[i - 1]:
                res += "1"
            else:
                res += "0"
            continue
        if 0 < i < N - 1:
            if n <= mi[i - 1] or n >= ma[i + 1]:
                res += "1"
            else:
                res += "0"
    print(res)
