def comp(ll):
    l = [0, 1, 0, 3, 2, 0, 2, 5]
    for i, c in enumerate(ll, 1):
        # print(c)
        if c in l:
            l.remove(c)
        if len(l) == 0:
            print(i)
            return
    print(0)


def main():

    tests = int(input())

    for _ in range(tests):
        input()
        l = list(map(int, input().split(" ")))
        comp(l)


main()
