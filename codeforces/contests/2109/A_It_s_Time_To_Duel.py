def comp(arr):
    if sum(arr) == len(arr):
        return "YES"
    for i in range(len(arr) - 1):
        if arr[i] == 0 and arr[i + 1] == 0:
            return "YES"
    return "NO"


n = int(input())
for i in range(n):
    size = int(input())
    arr = list(map(int, input().split()))
    print(comp(arr))
