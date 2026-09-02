# Problem A — Inversion Counter

Counts the number of inversions in an array using modified Merge Sort. A pair `(i, j)` is an inversion if `i < j` and `A[i] > A[j]`.

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
<n>
<a1> <a2> ... <an>
```

**Example:**
```
5
2 4 1 3 5
```
```
3
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

| # | Input | Expected output |
|---|-------|-----------------|
| 1 | `[1, 2, 3, 4, 5]` | `0` — already sorted, no element is out of order |
| 2 | `[5, 4, 3, 2, 1]` | `10` — fully reversed, maximum inversions `n*(n-1)/2` |
| 3 | `[2, 2, 1, 1]` | `4` — duplicates; equal elements are not inversions (strict `>`) |
