from typing import List


def getMaxExpectedProfit(N: int, V: List[int], C: int, S: float) -> float:

    dp = [0] * N
    dp[0] = V[0] - C
    for i in range(1, N):
        val = V[i]
        r = val - C + dp[i - 1]
        for j in range(i - 1, -1, -1):
            val += (1 - S) ** (i - j) * V[j]
            r = max(r, val - C + dp[j - 1])
        dp[i] = r
    return max(dp)


print(getMaxExpectedProfit(5, [10, 2, 8, 6, 4], 5, 0.0), 25.0)
print(getMaxExpectedProfit(5, [5, 5, 5, 5, 5], 5, 1), 0)
print(getMaxExpectedProfit(5, [10, 2, 8, 6, 4], 3, 0.15), 20.10825)
print(getMaxExpectedProfit(5, [10, 2, 8, 6, 4], 3, 0.5), 17.0)
print(getMaxExpectedProfit(5, [10, 10, 10, 10, 10], 3, 0.5), 17.0)

print(getMaxExpectedProfit(5, [10, 2, 8, 6, 4], 5, 1.0), 9.0)
