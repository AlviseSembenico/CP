# CP (Competitive Programming)

This repository contains solutions and code for various competitive programming challenges and projects. The structure is organized by folders representing different problem sets or topics.

## Folder Structure

- **.vscode/**: Contains workspace settings and configurations for Visual Studio Code.
- **csei/**: Likely related to specific problem sets or algorithms.
- **janestreet/**: Contains solutions or challenges related to Jane Street's monthly problems.
- **codeforces/**: Contains the solutions of the problem of codeforces website
- **lib/**: Collections of different types of algorithm.

## How to Use

1. Clone the repository:
   ```bash
   git clone https://github.com/AlviseSembenico/CP.git


# Wiki

## Backtracking

### Settle balances

Goal: having a vector of integers such that the sum of the values is 0, find the minimum number of transactions.

How: "simply" use backtrack, to find all possible transactions, change the array in place, so you restore it for the next branch search.

```
int dfs_settle(int start, vector<int>& debts) {
   // skip settled accounts
   while (start < debts.size() && debts[start] == 0)
      ++start;
   if (start == debts.size())
      return 0;

   int best = INT_MAX;
   for (int i = start + 1; i < debts.size(); ++i) {
      // only try to cancel opposite signs
      if (debts[i] * debts[start] < 0) {
            // settle debts[start] with debts[i]
            debts[i] += debts[start];
            best = min(best, 1 + dfs_settle(start + 1, debts));
            debts[i] -= debts[start];
            // prune: if debts[start] exactly cancels debts[i], no need to
            // try others
            if (debts[i] + debts[start] == 0)
               break;
      }
   }
   return best;
}
```