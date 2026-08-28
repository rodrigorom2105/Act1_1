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

void merge(vector<int> &nums, int left, int mid, int right, long long &inv)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  vector<int> L(n1, 0);
  vector<int> R(n2, 0);

  for (int i = 0; i < n1; i++)
  {
    L[i] = nums[left + i];
  }
  for (int j = 0; j < n2; j++)
  {
    R[j] = nums[mid + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = left;

  while ((i < n1) && (j < n2))
  {
    if (L[i] <= R[j])
    {
      nums[k] = L[i];
      i++;
    }
    else
    {
      nums[k] = R[j];
      j++;
      inv += n1 - i;
    }
    k++;
  }

  while (i < n1)
  {
    nums[k] = L[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    nums[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(vector<int> &nums, int low, int high, long long &inv)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    mergeSort(nums, low, mid, inv);
    mergeSort(nums, mid + 1, high, inv);
    merge(nums, low, mid, high, inv);
  }
}

int main()
{

  ios::sync_with_stdio(false);

  cin.tie(nullptr);

  int n;

  cin >> n;

  vector<int> a(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll inv = 0;

  mergeSort(a, 0, n - 1, inv);

  cout << inv << "\n";

  return 0;
}
