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
   ```

## Data Structure Reference

The following index links to the implementations and representative uses in this repository. Library files are snippets to copy into a solution; some also contain their own `main()`.

### Implementations and helpers

| Data structure | Operations / representation | Files |
| --- | --- | --- |
| Disjoint-set union (DSU / union-find) | `init`, `get`, `sameSet`, `size`, and `unite`; path compression and union by size. | [Library DSU](lib/cpp/unionfind/base.cpp), [standalone union-find](cses/Unionfind.cpp), [MST example](cses/Road_Reparation.cpp), [GCD and MST](cses/D_GCD_and_MST.cpp) |
| DSU with component statistics | Also maintains the component count (`nComp`) and largest component size (`bSize`). | [Road Construction](cses/Road_Construction.cpp) |
| Maximum segment tree | `SegmentTree`: point assignment with `update(idx, val)` and inclusive range maximum with `query(l, r)`; zero-based indices. | [Maximum segment tree](lib/cpp/segtree/max_seg_tree.cpp) |
| Sum segment tree | Inclusive range sums over `long long` values. The subtree-query solutions also support point assignment and flatten a tree into an array. | [Library `SegTree`](lib/cpp/intervals/misc.cpp), [function-based implementation](cses/1137.cpp), [class-based implementation](cses/1137_v2.cpp) |
| Trie | Lowercase `a`–`z` strings; `insert`, exact-word `search`, and prefix lookup with `startsWith`. | [Trie](lib/cpp/trie/base.cpp) |
| Graph adjacency lists | Unweighted `vector<vector<int>>`; `readUndirectedGraph()` converts one-based input to zero-based vertices. | [Graph reader](lib/cpp/graph/graph_base.cpp) |
| Weighted graphs and tree traversal helpers | Adjacency lists of `(neighbor, weight)` pairs or vectors; graph traversal and Euler flattening snippets. | [Weighted graph skeleton](lib/cpp/graph/base.cpp), [C++ graph helpers](lib/cpp/graph/graph.cpp), [Python tree diameter](lib/python/graph/misc.py) |
| Prefix-sum array | `prefixSum` stores the inclusive running sum at each index. | [Array helpers](lib/cpp/misc/main.cpp), [Maximum Subarray Sum II](cses/Maximum_Subarray_Sum_II.cpp) |
| Two-dimensional prefix sums | Cumulative grid counts for rectangle-sum queries. | [Forest Queries](cses/Forest_Queries.cpp) |
| Two- and three-dimensional grids | Nested vectors constructed with `make_2d`, `make_3d`, or the generic `createGrid<T>`. | [C++ template](codeforces/base.cpp), [grid helpers](codeforces/helper.cpp) |
| Hash containers with a custom hash | `custom_hash` uses SplitMix64 and a runtime seed for integer keys in `unordered_map` / `unordered_set`. | [Hash helper](codeforces/helper.cpp), [usage example](cses/Forest_Queries.cpp) |
| Python dictionary wrappers | `DDict(defaultdict)` and `Bict(dict)` convert keys to strings in bracket reads and writes. | [`DDict` template](codeforces/base.py), [`DDict` and `Bict`](codeforces/contests/1034/E_MEX_Count.py) |
| Modular integer wrapper | `mi` stores a value modulo `MOD` and overloads arithmetic operators; includes powers and modular inverses. | [Modular arithmetic](lib/cpp/modulo/misc.cpp) |
| Hexagonal grid | `HexagonalMatrix` wraps a NumPy matrix with row and diagonal access for the puzzle. | [Jane Street hexagonal matrix](janestreet/10-24/fence.py) |

The library sum-tree constructor currently calls `reserve()` before indexed writes; it needs `resize()` before reuse. The graph files also contain unfinished snippets, so adapt their initialization and indexing when copying them.

### Standard container examples

| Container / pattern | Files |
| --- | --- |
| Dynamic arrays (`vector`) and fixed-size arrays (`array`) | [C++ template](codeforces/base.cpp), [Jane Street matrix](janestreet/10-24/matrixm.cpp) |
| Ordered sets, maps, and multisets | [Traffic Lights](cses/Traffic_Lights.cpp), [Bit Inversions](cses/Bit_Inversions.cpp) |
| Hash maps and hash sets | [Hash helper](codeforces/helper.cpp), [GCD and MST](cses/D_GCD_and_MST.cpp) |
| Monotonic stacks | [Nearest Smaller Values](cses/Nearest_Smaller_Values.cpp), [Maximum Building I](cses/Maximum_Building_I.cpp) |
| Priority queues / heaps | [Flight Routes](cses/Flight_Routes.cpp), [custom `Table` ordering in Dining Hall](codeforces/contests/past/C_Dining_Hall.cpp) |
| Double-ended queues (`collections.deque`) | [Shrink](codeforces/mix/B_Shrink.py) |
| Python sets and adjacency lists | [Tree diameter](lib/python/graph/misc.py), [Cool Partition](codeforces/mix/C_Cool_Partition.py) |

## Syntactic Sugar and Type Aliases

Most solutions copy aliases and macros from [the C++ template](codeforces/base.cpp). With `using namespace std;`, standard types can be written without the `std::` prefix. `typedef` and `using` introduce alternate names for existing types.

| Alias | Underlying type | Reference |
| --- | --- | --- |
| `ll` | `long long int` (also written `long long`) | [Template](codeforces/base.cpp) |
| `lint` | `long long int`; an older spelling of `ll` | [Apple Division](cses/1623.cpp) |
| `pii` | `pair<int, int>` | [Template](codeforces/base.cpp) |
| `pil` | `pair<int, ll>` | [Template](codeforces/base.cpp) |
| `pll` | `pair<ll, ll>` | [Template](codeforces/base.cpp) |
| `vint` | `vector<int>` | [Template](codeforces/base.cpp) |
| `vlong` | `vector<ll>` | [Template](codeforces/base.cpp) |
| `Grid2D` | `vector<vector<int>>`; the maximum-path solution uses `ll` elements instead | [Template](codeforces/base.cpp), [Maximum Path](olinfo/ois_maxpath.cpp) |
| `Grid3D` | `vector<Grid2D>` | [Template](codeforces/base.cpp) |
| `T` | Function-local `pair<ll, int>` for `(distance, vertex)` | [Flight Routes](cses/Flight_Routes.cpp) |

| Shorthand | Expansion / use | Reference |
| --- | --- | --- |
| `pb` | `push_back`, e.g. `v.pb(x)` | [Template](codeforces/base.cpp) |
| `all(x)` | `x.begin(), x.end()`, e.g. `sort(all(v))` | [Template](codeforces/base.cpp) |
| `loop(a, b)` | `for (int i = a; i < b; i++)` | [Template](codeforces/base.cpp) |
| `loop0(a)` | `for (int i = 0; i < a; i++)` | [Template](codeforces/base.cpp) |
| `range(a, b)` | Same expansion as `loop(a, b)` | [Wildflower](codeforces/mix/F_Wildflower.cpp) |
| `contains(v, x)` / `icontains(v, x)` | Linear search using `find`, returning whether `x` exists | [Template](codeforces/base.cpp), [Monocarp's String](codeforces/contests/past/C_Monocarp_s_String.cpp) |
| `pp(a, b)` | `make_pair(a, b)` | [Shortest Routes II](cses/Shortest_Routes_II.cpp) |
| `graph` | Macro for `vector<vector<int>>` | [Course Schedule](cses/Course_Schedule.cpp) |
| `make_2d(n, m, val)` / `make_3d(n, m, k, val)` | Allocate nested integer vectors filled with `val` (default `0`) | [Template](codeforces/base.cpp) |
| `createGrid<T>(n, m, val)` | Allocate a two-dimensional vector of a chosen element type | [Helpers](codeforces/helper.cpp) |

The loop macros always declare `i`; use explicit loops when nesting needs distinct indices. The `contains` macros scan the container, unlike a set or map's member `.contains()`. Definitions vary between solutions, so copy the required aliases with a snippet.

Other conveniences include the vector `operator<<` in [helper.cpp](codeforces/helper.cpp), arithmetic operators on [`mi`](lib/cpp/modulo/misc.cpp), and structured bindings such as `auto [k, v]` in [debug.hpp](codeforces/debug.hpp). `MOD` is a solution-specific modulus, defined as a constant or macro; check its value before reusing modular code.

## Debugging

### Logging and container printing

The [C++ template](codeforces/base.cpp) has separate controls for logging and extra print helpers:

| Control | Behavior |
| --- | --- |
| `ONLINE_JUDGE` | When defined, `deb(...)` expands to nothing. Without it, `deb(...)` calls `logger` even when `DEBUG` is `0`. |
| `DEBUG` | Set the source's `#define DEBUG 0` to `1` to include [debug.hpp](codeforces/debug.hpp). A command-line `-DDEBUG=1` is overwritten by the source's unconditional definition. |
| `HAS_EXTRA` | Marker defined inside the `#if DEBUG` block; it does not enable the helpers by itself. |
| `CINPUT` | Where supported, defining it redirects standard input to `input.txt` via `freopen`. |

`deb(n, answer)` prints the expression names and values to `cout`, without a trailing newline. Its arguments must support `operator<<`; vectors and pairs are not printable by the base logger alone. For a complete diagnostic line:

```cpp
#ifndef ONLINE_JUDGE
deb(n, answer);
cout << '\n';
#endif
```

With `DEBUG` enabled, the header provides `printVector(v)`, `printVector(array, size)` for `int` / `long long` elements, and `printMap(m)` for `map<int, int>`. Guard those calls with `#if DEBUG` as well:

```cpp
#if DEBUG
printVector(values);
#endif
```

These helpers also write to standard output. Before submission, set `DEBUG` to `0` and ensure `ONLINE_JUDGE` is defined (or remove diagnostic calls). `ONLINE_JUDGE` alone does not disable the extra print helpers. Omit `CINPUT` so the judge can supply standard input.

### Local builds and VS Code

For a local debug build, use `-g -O0` to retain symbols and make stepping predictable. For example, from the repository root with a compiler that provides `bits/stdc++.h`:

```bash
clang++ -std=c++23 -g -O0 -Wall -Wextra -I . codeforces/base.cpp -o /tmp/cp-debug
/tmp/cp-debug < input.txt
```

Replace the source path with your solution. `-I .` lets copied includes such as `"./codeforces/debug.hpp"` resolve from the repository root when `DEBUG` is enabled. Alternatively, use an include path relative to the solution file. To compile with `deb(...)` disabled, add `-DONLINE_JUDGE`.

In VS Code, open the solution `.cpp`, set breakpoints, select **clang++ debug (cppdbg+LLDB)**, and press **F5**. The [launch configuration](.vscode/launch.json) invokes the [build task](.vscode/tasks.json) and runs the executable beside the active source file. This configuration needs the Microsoft C/C++ extension and LLDB support.

The current task passes `-DCINPUT=1`, so files using the `CINPUT` block need `input.txt` beside the source (the debugger's working directory). Remove that flag from the task to read input from the terminal. The task also passes `-DDEBUG1=1`; `DEBUG1` is a different name from `DEBUG` and does not enable the template's print helpers.


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
