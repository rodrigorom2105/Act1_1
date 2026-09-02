# Problem C — Budgeted Study Plan (0/1 Knapsack)

Finds the maximum learning value achievable within a time budget `T`, where each study module can be taken at most once. Solved with a 2D DP table in O(n × T).

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
<n> <T>
<time1> <value1>
<time2> <value2>
...
```

**Example:**
```
3 10
3 4
4 5
7 10
```
```
14
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

| # | Modules `(time, value)` | Budget `T` | Expected output |
|---|------------------------|------------|-----------------|
| 1 | `(3,4), (2,3), (1,2)` | `5` | `7` — tight budget exactly met: modules 1+2 give `3+2=5h`, `4+3=7pts` |
| 2 | `(4,100), (5,200), (6,300)` | `3` | `0` — all module times exceed `T`, nothing can be taken |
| 3 | `(5,1000000), (5,999999)` | `10` | `1999999` — both fit exactly, large values stress `long long` accumulation |
