# CP (Competitive Programming)

This repository contains solutions and code for various competitive programming challenges and projects. The structure is organized by folders representing different problem sets or topics.


## Compilation
Install clang. You can use `winget` if on windows.

Locate your `stdc++.h` file by CTRL-click on the include. 

Precompile the headers with
```
clang++ -std=c++23 -O0 -g0 `
   --target=x86_64-w6whe4-windows-gnu `
   -x c++-header "C:\msys64\ucrt64\include\c++\13.1.0\x86_64-w64-mingw32\bits\stdc++.h" `
   -o stdc++.pch
```

Now you can compile it much faster with
```
clang++  -std=c++23 -O0 -g0 `
  --target=x86_64-w6whe4-windows-gnu `
  -include-pch C:\Users\alvis\Documents\repos\CP\stdc++.pch `
  -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wno-sign-conversion `
  -ferror-limit=2 -D_GLIBCXX_ASSERTIONS `
  -fuse-ld=lld .\MYFILE.cpp
```


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

An extremely interesting case of non intuitive (at first) solution is about the longest increasing subsequence ([Cses problem](https://cses.fi/problemset/result/13339595/)).
The solution comes from [here](https://usaco.guide/gold/lis?lang=cpp), and it is connected to the [Patience sorting](https://en.wikipedia.org/wiki/Patience_sorting#Algorithm_for_finding_a_longest_increasing_subsequence).

```
int find_lis(const vector<int> &a) {
	vector<int> dp;
	for (int i : a) {
		int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
		if (pos == dp.size()) {
			// we can have a new, longer increasing subsequence!
			dp.push_back(i);
		} else {
			// oh ok, at least we can make the ending element smaller
			dp[pos] = i;
		}
	}
	return dp.size();
}
```