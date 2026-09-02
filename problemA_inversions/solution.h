#pragma once
#include <vector>
using namespace std;
using ll = long long;

static void _merge(vector<int> &nums, int left, int mid, int right, ll &inv)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  vector<int> L(n1), R(n2);
  for (int i = 0; i < n1; i++) L[i] = nums[left + i];
  for (int j = 0; j < n2; j++) R[j] = nums[mid + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j]) { nums[k] = L[i++]; }
    else              { nums[k] = R[j++]; inv += n1 - i; }
    k++;
  }
  while (i < n1) nums[k++] = L[i++];
  while (j < n2) nums[k++] = R[j++];
}

static void _mergeSort(vector<int> &nums, int low, int high, ll &inv)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    _mergeSort(nums, low, mid, inv);
    _mergeSort(nums, mid + 1, high, inv);
    _merge(nums, low, mid, high, inv);
  }
}

// Returns the number of inversions in nums (nums is sorted in-place as a side effect).
ll countInversions(vector<int> nums)
{
  ll inv = 0;
  _mergeSort(nums, 0, (int)nums.size() - 1, inv);
  return inv;
}
