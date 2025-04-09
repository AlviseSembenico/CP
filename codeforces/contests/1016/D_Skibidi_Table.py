from math import isqrt


def q1(a, b, x, y):
    # Base case: only one number in this range
    if a == b:
        return a

    length = b - a + 1
    # Use exact integer square root to avoid floating precision issues on large n
    n = isqrt(length)
    block = length // 4
    half = n // 2

    # top-left
    if x <= half and y <= half:
        return q1(a, a + block - 1, x, y)
    # bottom-right
    if x > half and y > half:
        return q1(a + block, a + 2 * block - 1, x - half, y - half)
    # bottom-left
    if x > half and y <= half:
        return q1(a + 2 * block, a + 3 * block - 1, x - half, y)
    # top-right
    return q1(a + 3 * block, b, x, y - half)


def q2(x1, x2, y1, y2, d):
    # Base case: single cell
    if x1 == x2 and y1 == y2:
        return x1, y1

    a = x2 - x1 + 1  # number of rows
    b = y2 - y1 + 1  # number of columns
    total = a * b
    block = total // 4

    # top-left
    if d <= block:
        return q2(x1, x1 + a // 2 - 1, y1, y1 + b // 2 - 1, d)
    # bottom-right
    if d <= 2 * block:
        return q2(x1 + a // 2, x2, y1 + b // 2, y2, d - block)
    # bottom-left
    if d <= 3 * block:
        return q2(x1 + a // 2, x2, y1, y1 + b // 2 - 1, d - 2 * block)
    # top-right
    return q2(x1, x1 + a // 2 - 1, y1 + b // 2, y2, d - 3 * block)


t = int(input())
for _ in range(t):
    n = int(input())
    q = int(input())
    # The table has cells from 1..(2^n)*(2^n) = 2^(2n)
    # So we call q1(1, 2^(2n), x, y) and q2(1, 2^n, 1, 2^n, d)
    upper_bound = (2**n) ** 2
    dimension = 2**n

    for _q in range(q):
        line = input().strip()
        if line[0] == "-":  # -> x y
            _, x, y = line.split()
            x, y = int(x), int(y)
            print(q1(1, upper_bound, x, y))
        else:  # <- d
            _, d = line.split()
            d = int(d)
            print(*q2(1, dimension, 1, dimension, d))
