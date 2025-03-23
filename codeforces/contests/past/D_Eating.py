from copy import deepcopy


def comp(ws, qs):
    
    
# def comp(ws, qs):
#     res = []

#     for q in qs:
#         i = len(ws) - 1
#         c = 0
#         while q >= ws[i] and i >= 0:
#             q = q ^ ws[i]
#             c += 1
#             i -= 1
#         res.append(c)
#     return res


def main():
    test = int(input())
    for i in range(test):
        n, q = (int(i) for i in input().split(" "))

        ws = [int(i) for i in input().split(" ")]
        qs = []
        for _ in range(q):
            qs.append(int(input()))

        print(*comp(ws, qs))


main()
