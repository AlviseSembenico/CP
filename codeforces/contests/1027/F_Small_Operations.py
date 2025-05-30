from collections import Counter, defaultdict, deque

n = int(input())


def prime_factors(n):
    i = 2
    factors = Counter()
    while i * i <= n:
        while n % i == 0:
            factors[i] += 1
            n //= i
        i += 1
    if n > 1:
        factors[n] += 1
    return factors


def cal(fact, k):
    res = 0
    fact.sort(reverse=True)
    fact = deque(fact)
    while fact:
        curr = fact.popleft()
        if curr > k:
            return -1
        while fact and curr * fact[len(fact) - 1] <= k:
            curr *= fact.pop()
        res += 1
    return res


def comp(x, y, k):
    px = prime_factors(x)
    py = prime_factors(y)
    py.subtract(px)
    f_pos = []
    f_neg = []
    for key, v in py.items():
        if v > 0:
            f_pos += [key] * v
        elif v < 0:
            f_neg += [key] * -v

    p = cal(f_pos, k)
    if p == -1:
        return -1

    n = cal(f_neg, k)
    if n == -1:
        return -1
    return p + n


for _ in range(n):
    x, y, k = map(int, input().split())
    print(comp(x, y, k))
