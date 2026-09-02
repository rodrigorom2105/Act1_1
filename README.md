# Activity 1 — Algorithm Design & Analysis

Three problems solved using divide-and-conquer, greedy, and dynamic programming strategies. Each problem lives in its own folder with a `solution.h` (algorithm logic), `main.cpp` (interactive stdin runner), and `tests/test.cpp` (3 hardcoded tests).

---

## Requirements

- C++17 or later
- A C++ compiler: `g++` (GCC), `clang++`, or MSVC

---

## Project Structure

```
.
├── report.md
├── problemA_inversions/
│   ├── solution.h
│   ├── main.cpp
│   └── tests/test.cpp
├── problemB_rooms/
│   ├── solution.h
│   ├── main.cpp
│   └── tests/test.cpp
└── problemC_knapsack/
    ├── solution.h
    ├── main.cpp
    └── tests/test.cpp
```

---

## Problem A — Inversion Counter

Counts inversions in an array (pairs `(i,j)` where `i < j` and `A[i] > A[j]`) using modified Merge Sort in O(n log n).

**Compile & run (custom input):**
```bash
g++ -std=c++17 -o main problemA_inversions/main.cpp
./main
```

**Input format:**
```
<n>
<a1> <a2> ... <an>
```

**Example:**
```bash
$ echo "5\n2 4 1 3 5" | ./main
3
```

**Compile & run tests:**
```bash
g++ -std=c++17 -o test problemA_inversions/tests/test.cpp
./test
```

---

## Problem B — Minimum Meeting Rooms

Finds the minimum number of rooms to schedule `m` non-conflicting meetings using a greedy sort + max-heap in O(m log m).

**Compile & run (custom input):**
```bash
g++ -std=c++17 -o main problemB_rooms/main.cpp
./main
```

**Input format:**
```
<m>
<start1> <end1>
<start2> <end2>
...
```

**Example:**
```bash
$ printf "3\n0 30\n5 10\n15 20\n" | ./main
2
```

**Compile & run tests:**
```bash
g++ -std=c++17 -o test problemB_rooms/tests/test.cpp
./test
```

---

## Problem C — Budgeted Study Plan (0/1 Knapsack)

Maximizes learning value within a time budget `T` using a 2D DP table in O(n × T). Each module can be taken at most once.

**Compile & run (custom input):**
```bash
g++ -std=c++17 -o main problemC_knapsack/main.cpp
./main
```

**Input format:**
```
<n> <T>
<time1> <value1>
<time2> <value2>
...
```

**Example:**
```bash
$ printf "3 10\n3 4\n4 5\n7 10\n" | ./main
14
```

**Compile & run tests:**
```bash
g++ -std=c++17 -o test problemC_knapsack/tests/test.cpp
./test
```

---

## Assumptions

- **Problem A:** Output may exceed 32-bit range; the result is stored in a `long long`. Input values fit in a 32-bit signed integer.
- **Problem B:** A meeting ending at time `t` and another starting at time `t` are considered non-overlapping and may share a room. Times can be up to `10⁹` and are stored as `long long`.
- **Problem C:** Module values can be large (up to `10⁶` each); totals are stored in `long long`. The DP table allocates O(n × T) memory.
- All solutions read from **stdin** and write to **stdout**. Input is assumed to be well-formed; no error handling for malformed input.
