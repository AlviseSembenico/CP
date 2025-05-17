def comp(l):
    odd = []
    even = []
    for i in range(len(l)):
        if i % 2 == 0:
            even.append(l[i])
        else:
            odd.append(l[i])

    def parity(seq):
        k = len(seq)
        # compress to 0..k-1
        order = {v: i for i, v in enumerate(sorted(seq))}
        perm = [order[v] for v in seq]
        seen = [False] * k
        cycles = 0
        for i in range(k):
            if not seen[i]:
                cycles += 1
                j = i
                while not seen[j]:
                    seen[j] = True
                    j = perm[j]
        # sign = (k − #cycles) mod 2
        return (k - cycles) & 1

    p1 = parity(odd)
    p2 = parity(even)
    even.sort()
    odd.sort()

    def merge(even, odd):
        res = []
        for i in range(len(l)):
            if i % 2 == 0:
                res.append(even[i // 2])
            else:
                res.append(odd[i // 2])
        return res

    if p1 == p2:
        return merge(even, odd)
    else:
        return min(
            merge(even[:-2] + [even[-1], even[-2]], odd),
            merge(even, odd[:-2] + [odd[-1], odd[-2]]),
        )


n = int(input())

for _ in range(n):
    size = int(input())
    arr = list(map(int, input().split()))
    res = comp(arr)
    print(" ".join(map(str, res)))
