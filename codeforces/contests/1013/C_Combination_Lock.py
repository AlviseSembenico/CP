def comp(n):
    res = [1]
    res_s = [False] * (n + 5)
    res_s[1] = True
    for i in range(1, n):
        np = (i + i) % (n) + 1
        if res_s[np]:
            print(-1)
            return
        res.append(np)
        res_s[np] = True
    print(*res, sep=" ")
    return res


def main():

    tests = int(input())

    for _ in range(tests):
        n = int(input())
        res = comp(n)


main()
