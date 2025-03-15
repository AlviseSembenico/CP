n = int(input())
for i in range(n):
    input()
    vals = [int(i) for i in input().split(" ")]
    print(sum(vals) - len(vals) + 1)
