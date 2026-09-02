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
  // Test 1: tight budget — budget T=5 is exactly met by taking modules 1+2
  // (t=3,v=4)+(t=2,v=3) = 5 hours, 7 points; better than any other combination
  check("Tight budget T=5",
        calculateMax({3, 2, 1}, {4, 3, 2}, 5),
        7);

  // Test 2: all times exceed T — nothing fits, answer must be 0
  check("All times > T (T=3)",
        calculateMax({4, 5, 6}, {100, 200, 300}, 3),
        0);

  // Test 3: large values — both items fit exactly (5+5=10=T), totaling 1,999,999
  check("Large values T=10",
        calculateMax({5, 5}, {1000000, 999999}, 10),
        1999999);

  std::cout << "\n" << passed << "/" << (passed + failed) << " tests passed.\n";
  return failed == 0 ? 0 : 1;
}
