from typing import List


def getMaxExpectedProfit(N: int, V: List[int], C: int, S: float) -> float:

    d = {}

    def main(i, value):
        if (i, value) in d:
            return d[(i, value)]
        if i >= N:
            return 0
        value += V[i]
        new_value = value * (1 - S)
        res = max(value - C + main(i + 1, 0), main(i + 1, new_value))
        d[(i, value)] = res
        return res

    return main(0, 0)


print(getMaxExpectedProfit(5, [10, 2, 8, 6, 4], 5, 1), 9)
print(getMaxExpectedProfit(5, [10, 2, 8, 6, 4], 3, 0.5), 17)
print(getMaxExpectedProfit(5, [10, 2, 8, 6, 4], 3, 0.15), 20.10825)
