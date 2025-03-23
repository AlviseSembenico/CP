def ack(n, m):
    if n == 0:
        print(m + 1, end="")
        return m + 1
    if m == 0:
        print("ack(", end="")
        a = ack(n - 1, 1)
        print(") ", end="")
        return a

    print("ack(", end="")
    a = ack(n - 1, ack(n, m - 1))
    print(") ", end="")
    return a


ack(2, 1)
