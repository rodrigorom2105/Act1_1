/*
* Problem A — “Inversion Counter for Quality Control”
* You are given an array A of n integers. A pair (i, j) is an inversion if i < j and A[i] > A[j].

TODO: Compute the number of inversions in the array.

Input:
- An integer n
- A list of n integers

Output:
 - A single integer: the inversion count

! Constraints (suggested):
! 1 ≤ n ≤ 2 * 10^5

Values fit in 32-bit signed int
Output may exceed 32-bit; use 64-bit integer.

* * Example
* * - Input: A = [2, 4, 1, 3, 5]
* * - Output: 3
* * (inversions: (2,1), (4,1), (4,3))

? Notes
? A direct O(n^2) approach will be too slow for the upper constraints.
? Your algorithm should scale to large n.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{

  ios::sync_with_stdio(false);

  cin.tie(nullptr);

  int n;

  cin >> n;

  vector<long long> a(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  // TODO: implement efficient inversion counting

  // Print the number of inversions as a 64-bit integer.

  ll inv = 0;

  cout << inv << "\n";

  return 0;
}
