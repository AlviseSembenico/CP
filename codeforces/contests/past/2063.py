def min_coprime(a, b):
    if a == b == 1:
        return 1
    return b - a


def main():
    n = int(input())
    for i in range(n):
        vs = [int(x) for x in input().split(" ")]
        print(min_coprime(*vs))


def main_file():
    with open("2063.txt") as infile:
        n = int(infile.readline())
        for i in range(n):
            vs = [int(x) for x in infile.readline().split(" ")]
            print(min_coprime(*vs))


# main_file()
main()
