# Activity 1 Report

---

## Table of Contents

1. [Problem A — Inversion Counter](#problem-a--inversion-counter-for-quality-control)
2. [Problem B — Minimum Meeting Rooms](#problem-b--minimum-meeting-rooms)
3. [Problem C — Budgeted Study Plan (0/1 Knapsack)](#problem-c--budgeted-study-plan-01-knapsack)

---

---

# Problem A — Inversion Counter for Quality Control

## Problem Summary

Given an array `A` of `n` integers, a pair `(i, j)` is called an **inversion** if `i < j` and `A[i] > A[j]` — that is, a larger element appears before a smaller one. The goal is to count the total number of such inversions in the array.

This metric has practical relevance in quality control and ranking systems: the inversion count measures how far a sequence is from being sorted. An array already in ascending order has zero inversions, while a fully reversed array has the maximum possible count of `n*(n-1)/2`. With `n` up to `2 × 10⁵`, a naïve O(n²) scan is too slow and an efficient divide-and-conquer approach is required.

---

## Algorithm Idea

The solution is a **modified Merge Sort**. The key observation is that during a standard merge step, when an element from the right sub-array is placed before remaining elements of the left sub-array, each of those remaining left elements forms an inversion with the current right element. By counting these cases during every merge, the total inversion count accumulates naturally as the sort proceeds.

The recursion splits the array in half, counts inversions on each side, and then counts **split inversions** (pairs where one element is in the left half and the other in the right) during the merge. Since both halves are sorted at merge time, split inversions can be counted in O(n) per level.

---

## Pseudocode

```
function mergeSort(nums, low, high, inv):
    if low >= high:
        return

    mid = (low + high) / 2
    mergeSort(nums, low, mid, inv)
    mergeSort(nums, mid + 1, high, inv)
    merge(nums, low, mid, high, inv)

function merge(nums, left, mid, right, inv):
    L = nums[left .. mid]
    R = nums[mid+1 .. right]
    i = 0, j = 0, k = left

    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            nums[k] = L[i]
            i++
        else:
            nums[k] = R[j]
            j++
            inv += len(L) - i   // all remaining L elements are inversions with R[j]
        k++

    copy remaining elements of L and R into nums
```

---

## Example Run

**Input:**
```
5
2 4 1 3 5
```

**Execution trace (merge steps):**

| Step | Left subarray | Right subarray | Inversions found | Running total |
|------|---------------|----------------|-----------------|---------------|
| Merge `[2]` and `[4]` | `[2]` | `[4]` | 0 | 0 |
| Merge `[2,4]` and `[1]` | `[2,4]` | `[1]` | 2 &nbsp;(`2>1`, `4>1`) | 2 |
| Merge `[3]` and `[5]` | `[3]` | `[5]` | 0 | 2 |
| Merge `[1,2,4]` and `[3,5]` | `[1,2,4]` | `[3,5]` | 1 &nbsp;(`4>3`) | **3** |

**Output:**
```
3
```

The three inversions are the pairs `(2,1)`, `(4,1)`, and `(4,3)`.

---

## Complexity Analysis

### Time Complexity — O(n log n)

The recurrence follows that of standard Merge Sort:

```
T(n) = 2·T(n/2) + O(n)
```

- Each call splits the problem into two halves: `2·T(n/2)`.
- The merge step, including the inversion counting, is linear in the subarray size: `O(n)`.

By the **Master Theorem** (case 2): `a = 2`, `b = 2`, `f(n) = O(n)` → `n^(log_b a) = n^1 = n` → **T(n) = O(n log n)**.

There are `log n` levels of recursion, and each level processes a total of `n` elements across all merge calls.

### Space Complexity — O(n)

Each merge call allocates two temporary arrays `L` and `R` whose combined size equals the subarray being merged. Across any single level of recursion, the total auxiliary space is `O(n)`. The recursion stack itself uses `O(log n)` space. Therefore total space is **O(n)**.

---

---

# Problem B — Minimum Meeting Rooms

## Problem Summary

Given `m` meetings, each defined by a start time `s_i` and an end time `e_i` (`s_i < e_i`), a single room can host at most one meeting at a time. Two meetings that share a boundary (one ends exactly when the next begins) are considered **non-overlapping** and may use the same room. The task is to find the minimum number of rooms needed to schedule all meetings without conflict.

The problem reduces to finding the maximum number of meetings that are simultaneously active at any single point in time. With times ranging up to `10⁹` and up to `2 × 10⁵` meetings, the solution must avoid brute-force overlap checks and instead exploit a sorted greedy strategy.

---

## Algorithm Idea

The algorithm uses a **greedy sweep with a max-heap**:

1. **Sort meetings by end time in descending order.** This means the meeting with the latest end time is processed first.
2. **Maintain a max-heap of start times** for meetings that have been assigned to rooms.
3. For each meeting (processed latest-ending first), check whether its end time is ≤ the largest start time currently in the heap. If so, this meeting ends before that other meeting begins — they do not overlap — so they can share a room (pop the heap entry and reuse the room).
4. Push the current meeting's start time onto the heap regardless.
5. At the end, **the heap size equals the number of rooms required**, since each element in the heap represents a distinct room that could not be merged with any later-ending meeting.

The key insight: when processing meeting `i` (with a relatively smaller end time), if its end time `e_i` is ≤ the maximum start time in the heap, then at least one already-assigned meeting starts after `i` finishes — so they are compatible in the same room.

---

## Pseudocode

```
function calculateRooms(meetings):
    sort meetings by end time DESCENDING
    maxHeap = empty max-heap of start times

    for each meeting (s, e) in sorted order:
        if maxHeap is not empty and e <= maxHeap.top():
            maxHeap.pop()           // reuse a room: this meeting ends before the top one starts
        maxHeap.push(s)             // assign meeting to a room (new or reused)

    return maxHeap.size()           // number of distinct rooms
```

---

## Example Run

**Input:**
```
3
0 30
5 10
15 20
```

**After sorting by end time descending:** `(0,30)`, `(15,20)`, `(5,10)`

| Step | Meeting `(s, e)` | Heap top | `e ≤ top`? | Action | Heap state |
|------|-----------------|----------|------------|--------|-----------|
| 1 | `(0, 30)` | — | — | Push 0 | `{0}` |
| 2 | `(15, 20)` | 0 | 20 ≤ 0? No | Push 15 | `{15, 0}` |
| 3 | `(5, 10)` | 15 | 10 ≤ 15? Yes | Pop 15, Push 5 | `{5, 0}` |

**Heap size = 2.**

**Output:**
```
2
```

Meetings `(0,30)` and `(15,20)` overlap (both active between minutes 15–20), so they need separate rooms. Meeting `(5,10)` ends before `(15,20)` starts and shares a room with it.

---

## Complexity Analysis

### Time Complexity — O(m log m)

- **Sorting:** `O(m log m)` using `std::sort`.
- **Heap operations:** Each of the `m` meetings involves at most one `pop` and exactly one `push`, each costing `O(log m)` on a heap of at most `m` elements. Total: `O(m log m)`.

Overall: **O(m log m)**.

### Space Complexity — O(m)

The heap holds at most `m` start times simultaneously (one per meeting in the worst case where no meetings can share a room). Therefore space is **O(m)**.

---

---

# Problem C — Budgeted Study Plan (0/1 Knapsack)

## Problem Summary

There are `n` study modules, each requiring `time[i]` hours and yielding `value[i]` learning points. A total time budget of `T` hours is available. Each module can be taken **at most once** (0/1 knapsack). The objective is to select a subset of modules that maximizes total value without exceeding the budget `T`.

This is a classic **NP-hard** combinatorial optimization problem. Although no known polynomial-time algorithm exists in general, the constraints (`n ≤ 2000`, `T ≤ 5000`) make it tractable via dynamic programming: the state space is `O(n × T)`, which is at most `10⁷` — manageable in practice.

---

## Algorithm Idea

The solution uses a **2D DP table**. Let `dp[i][j]` represent the maximum value achievable using only the first `i` modules with a time budget of exactly `j` hours.

For each module `i` and each budget `j`, there are two choices:
- **Skip module `i`:** `dp[i][j] = dp[i-1][j]`
- **Take module `i`** (only if `time[i] ≤ j`): `dp[i][j] = dp[i-1][j - time[i]] + value[i]`

The answer is `dp[n][T]`.

---

## Pseudocode

```
function calculateMax(time[], value[], n, T):
    dp[0..n][0..T] = 0       // base case: 0 modules or 0 budget → 0 value

    for i from 1 to n:
        for j from 1 to T:
            dp[i][j] = dp[i-1][j]                      // option 1: skip module i

            if time[i] <= j:
                take = dp[i-1][j - time[i]] + value[i]
                dp[i][j] = max(dp[i][j], take)          // option 2: include module i

    return dp[n][T]
```

---

## Example Run

**Input:**
```
3 10
3 4
4 5
7 10
```

Modules: `(time=3, value=4)`, `(time=4, value=5)`, `(time=7, value=10)`. Budget `T = 10`.

**DP table (selected columns):**

| `dp[i][j]` | j=0 | j=3 | j=4 | j=7 | j=10 |
|------------|-----|-----|-----|-----|------|
| i=0 (none) | 0 | 0 | 0 | 0 | 0 |
| i=1 (t=3,v=4) | 0 | 4 | 4 | 4 | 4 |
| i=2 (t=4,v=5) | 0 | 4 | 5 | 9 | 9 |
| i=3 (t=7,v=10) | 0 | 4 | 5 | 10 | **14** |

At `dp[3][10]`: taking module 1 (t=3, v=4) and module 3 (t=7, v=10) costs `3+7=10` hours and yields `4+10=14` points. Taking modules 1+2+3 would cost `3+4+7=14 > 10`, which exceeds the budget.

**Output:**
```
14
```

---

## Complexity Analysis

### Time Complexity — O(n × T)

The algorithm fills an `(n+1) × (T+1)` table. Each cell is computed in O(1) (a comparison and a max). Total operations:

```
(n + 1) × (T + 1)  ≈  n × T
```

With `n ≤ 2000` and `T ≤ 5000`, this is at most **10⁷ operations** — well within practical limits.

### Space Complexity — O(n × T)

The DP table has `(n+1) × (T+1)` entries, each storing a 64-bit integer. This is **O(n × T)**, or roughly `2001 × 5001 × 8 bytes ≈ 80 MB` at maximum constraints.

> **Note:** Space can be reduced to **O(T)** by keeping only the previous row (iterating `j` in reverse), since `dp[i][j]` only depends on `dp[i-1][...]`. The current implementation uses the full 2D table for clarity.

---
