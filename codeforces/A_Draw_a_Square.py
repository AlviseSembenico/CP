n = int(input())
for i in range(n):
    a, b, c, d = [int(i) for i in input().split(" ")]
    if a == b == c == d:
        print("Yes")
    else:
        print("No")
