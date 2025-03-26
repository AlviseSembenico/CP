def comp(l, k):
    l.sort()
    res = 0
    curr_size = 0
    while l:
        curr_size += 1
        if curr_size * l.pop() >= k:
            res += 1
            curr_size = 0
    return res


def main():

    tests = int(input())

    for _ in range(tests):
        n, k = list(map(int, input().split(" ")))
        l = list(map(int, input().split(" ")))

        print(comp(l, k))


main()
