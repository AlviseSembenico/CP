N = int(input())


def f(a, b, x, y):
    if a > b:
        if a ^ 1 == b:
            return y
        return -1
    if a == b:
        return 0
    if a % 2 == 0 and y < x:
        return y + f(a + 1, b, x, y)
    return f(a + 1, b, x, y) + x


for _ in range(N):
    a, b, x, y = list(map(int, input().split(" ")))
    print(f(a, b, x, y))
