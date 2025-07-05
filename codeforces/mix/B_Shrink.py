from collections import deque

n = int(input())


def comp(n):
    d = deque([n])
    right = True
    n -= 1
    while n:
        if right:
            d.append(n)
        else:
            d.appendleft(n)
        right = not right
        n -= 1
    return list(d)  # Convert deque to list for easier printing


for _ in range(n):
    m = int(input())
    print(" ".join(map(str, comp(m))))  # Assuming comp returns a list of strings
