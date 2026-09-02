#include <iostream>
#include <vector>
#include "../solution.h"

static int passed = 0, failed = 0;

static void check(const char *name, long long got, long long expected)
{
  if (got == expected)
  {
    std::cout << "[PASS] " << name << "\n";
    passed++;
  }
  else
  {
    std::cout << "[FAIL] " << name
              << "  expected=" << expected << "  got=" << got << "\n";
    failed++;
  }
}

int main()
{
  // Test 1: already sorted — no element is out of order
  check("Already sorted [1,2,3,4,5]",
        countInversions({1, 2, 3, 4, 5}),
        0);

  // Test 2: reverse sorted — every pair is an inversion: n*(n-1)/2 = 10
  check("Reverse sorted [5,4,3,2,1]",
        countInversions({5, 4, 3, 2, 1}),
        10);

  // Test 3: duplicates — equal elements are NOT inversions (A[i] > A[j], strict)
  // [2,2,1,1]: pairs (0,2),(0,3),(1,2),(1,3) → 4 inversions
  check("Duplicates [2,2,1,1]",
        countInversions({2, 2, 1, 1}),
        4);

  std::cout << "\n" << passed << "/" << (passed + failed) << " tests passed.\n";
  return failed == 0 ? 0 : 1;
}
