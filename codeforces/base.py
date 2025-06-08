from collections import defaultdict


class DDict(defaultdict):

    def __setitem__(self, key, value):
        return super().__setitem__(str(key), value)

    def __getitem__(self, key):
        return super().__getitem__(str(key))


c = DDict(int)


def comp(): ...


def main():

    tests = int(input())

    for _ in range(tests):
        n, k = list(map(int, input().split(" ")))
        l = list(map(int, input().split(" ")))

        comp(n, k, l)


main()
