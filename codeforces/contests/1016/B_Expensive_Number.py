tests = int(input())
for i in range(tests):
    n = input()
    if len(n) == 1:
        print(0)
        continue
    if "0" not in n:
        print(len(n) - 1)
        continue
    ind = -1
    for j in range(len(n) - 1, -1, -1):
        if n[j] != "0":
            ind = j
            break
    res = len(n) - ind - 1
    # print(ind)
    for i in range(ind):
        if n[i] != "0":
            res += 1
    print(res)
