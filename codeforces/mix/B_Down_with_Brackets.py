n = int(input())


def bl(s):
    st = 0
    for i, c in enumerate(s):
        if c == "(":
            st += 1
        elif c == ")":
            st -= 1
            if st == 0 and i != len(s) - 1:
                return "YES"
    return "NO"


for _ in range(n):
    brackets = input()
    print(bl(brackets))
