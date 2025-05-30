import math

n = int(input())
for i in range(n):
    s = int(input())
    if s == 0:
        print("0 0")
        continue
    if int(math.sqrt(s)) ** 2 != s:
        print(-1)
        continue
    sq = int(math.sqrt(s))
    print(f"1 {sq-1}")
