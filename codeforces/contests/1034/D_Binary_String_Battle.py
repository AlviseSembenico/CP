t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    a = input()
    n1 = a.count("1")
    if n1 <= k:
        print("Alice")
        continue

    if k > n / 2:
        print("Alice")
    else:
        print("Bob")
