n = int(input())

for i in range(n):
    n, m, p, q = list(map(int, input().split()))
    if n % p != 0:
        print("YES")
        continue
    if q * (n // p) != m:
        print("NO")
        continue
    print("YES")
    continue
