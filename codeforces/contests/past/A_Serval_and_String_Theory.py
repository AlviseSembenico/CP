def comp(k, s):
    if len(set(s)) == 1:
        print("NO")
        return
    if k == 0:
        if s < s[::-1]:
            print("YES")
            return
        else:
            print("NO")
            return
    print("YES")
    return


def main():

    tests = int(input())

    for _ in range(tests):
        n, k = list(map(int, input().split(" ")))
        l = list(input())
        comp(k, l)


main()
