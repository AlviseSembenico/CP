def comp(s):
    res = -int(s[0] == "0")
    prev = None
    for c in s:
        if c != prev:
            res += 1
        prev = c
    return res


def main():
    n = int(input())
    for i in range(n):
        input()
        s = input()
        print(comp(s))


main()
