# Write any import statements here
# def check(S, k):
import math
from collections import defaultdict
from typing import List


def getMinProblemCount(N: int, S: List[int]) -> int:
    n1 = False
    n2 = False
    n0 = False
    n11 = min(S) == 1
    for i in S:
        if i % 3 == 2:
            n2 = True
        elif i % 3 == 1:
            n1 = True
        if i % 3 == 0:
            n0 = True
    mm = max(S)

    res = math.floor(mm / 3)
    if mm % 3 == 0 and (n1 and n2):
        res += 1
    if mm % 3 == 0 and (n1 ^ n2):
        res += 1
    if mm % 3 != 0:
        res += n1 + n2
    if not n11 and (n1 and n2) and (mm % 3 == 1) and not n0:
        res -= 1
    return res


print(getMinProblemCount(5, [1, 2, 3, 4, 5]), 3)
print(getMinProblemCount(4, [4, 3, 3, 4]), 2)
print(getMinProblemCount(4, [2, 4, 6, 8]), 4)
print(getMinProblemCount(1, [8]), 3)
print(getMinProblemCount(1, [1, 2, 9]), 4)
print(getMinProblemCount(1, [1, 2, 10]), 5)
print(getMinProblemCount(1, [1, 10]), 4)

print(getMinProblemCount(1, [2, 4, 7]), 3)
print(getMinProblemCount(1, [1, 3]), 2)
print(getMinProblemCount(1, [2, 3, 4]), 3)
