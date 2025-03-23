def comp(): ...


def main():

    tests = int(input())

    for _ in range(tests):
        n, k = list(map(int, input().split(" ")))
        l = list(map(int, input().split(" ")))

        comp(n, k, l)


main()
