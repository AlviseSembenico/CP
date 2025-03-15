inf = float("inf")


def sub(l, r, n):
    vs = n[l:r]
    vs.sort(reverse=True)
    res = inf
    # print("---")
    # print(l, r, n)
    for cp in [n[:l], n[r:]]:
        cp.sort()
        i = 0
        while i < len(cp) and i < len(vs) and cp[i] < vs[i]:
            i += 1
        cost = sum(cp[:i]) + sum(vs[i:])
        res = min(res, cost)
        # print(cp, cost)
    return res


def main():
    n = int(input())
    for i in range(n):
        n, l, r = (int(x) for x in input().split(" "))

        n = [int(x) for x in input().split(" ")]
        print(sub(l - 1, r, n))


main()
