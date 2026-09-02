#include <iostream>
#include <vector>
#include "../solution.h"

static int passed = 0, failed = 0;

static void check(const char *name, int got, int expected)
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
  // Test 1: many identical start times — all begin at 0, all overlap → one room each
  check("Identical start times (0,3)(0,5)(0,7)",
        minRooms({{0, 3}, {0, 5}, {0, 7}}),
        3);

  // Test 2: nested intervals — each meeting is fully contained inside the previous,
  // all three are active simultaneously → 3 rooms
  check("Nested intervals (1,10)(2,8)(3,6)",
        minRooms({{1, 10}, {2, 8}, {3, 6}}),
        3);

  // Test 3: back-to-back meetings — boundary touches are non-overlapping,
  // a single room handles all three in sequence
  check("Back-to-back (0,5)(5,10)(10,15)",
        minRooms({{0, 5}, {5, 10}, {10, 15}}),
        1);

  std::cout << "\n" << passed << "/" << (passed + failed) << " tests passed.\n";
  return failed == 0 ? 0 : 1;
}
