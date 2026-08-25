def factorize(n):
    if n == 1:
        return []
    res = [n]
    for i in range(2, n // 2 + 1):
        if n % i == 0:
            res.append(i)
    return res


print(factorize(8))
