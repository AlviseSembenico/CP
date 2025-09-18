t = int(input())

for _ in range(t):
    input()
    l = list(map(int, input().split(" ")))
    s = sum(l)
    n = len(l)
    if sorted(l) != list(range(1, n + 1)):
        print("NOo")
        continue
    i = l.index(n)
    j = i
    err = False
    for t in range(n - 1, 0, -1):
        if i > 0 and l[i - 1] == t:
            i -= 1
            continue
        if j < n - 1 and l[j + 1] == t:
            j += 1
            continue
        print("NO")
        err = True
        break
    if not err:
        print("YES")
