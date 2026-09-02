# Problem B — Minimum Meeting Rooms

Finds the minimum number of rooms needed to schedule all meetings without conflict, using a greedy sweep with a max-heap. Two meetings sharing a boundary (one ends when the next begins) are considered non-overlapping.

---

## Custom input — `main.cpp`

**Compile:**
```bash
g++ -std=c++17 -o main main.cpp
```

**Run:**
```bash
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
```
3
0 30
5 10
15 20
```
```
2
```

You can also pipe input from a file:
```bash
./main < input.txt
```

---

## Hardcoded tests — `tests/test.cpp`

**Compile:**
```bash
g++ -std=c++17 -o test tests/test.cpp
```

**Run:**
```bash
./test
```

| # | Meetings | Expected output |
|---|----------|-----------------|
| 1 | `(0,3), (0,5), (0,7)` | `3` — identical start times, all overlap simultaneously |
| 2 | `(1,10), (2,8), (3,6)` | `3` — nested intervals, all three active at the same time |
| 3 | `(0,5), (5,10), (10,15)` | `1` — back-to-back, boundary touches are non-overlapping |
