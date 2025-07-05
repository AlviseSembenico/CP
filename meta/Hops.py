from typing import List

# Write any import statements here

def getSecondsRequired(N: int, F: int, P: List[int]) -> int:
  P.sort()
  res = 0 
  for i in range(F-1):
    res += P[i+1]-P[i]-1
  res += N-1-P[-1] +F
  return res