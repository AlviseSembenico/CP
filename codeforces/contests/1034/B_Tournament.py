from collections import Counter

t = int(input())
for _ in range(t):
    n, j, k = map(int, input().split())
    j -= 1
    a = list(map(int, input().split()))
    jp = a[j]
    if k != 1:
        print("YES")
        continue
    if k == 1:
        if jp == max(a):
            print("YES")
        else:
            print("NO")
