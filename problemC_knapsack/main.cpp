/*
* Problem C — “Budgeted Study Plan (0/1 Knapsack Variant)”
* You have n study modules. Each module i requires time[i] hours and yields value[i] points of learning benefit. You have a total available time budget T. Each module can be taken at most once.

TODO: Compute the maximum total value achievable without exceeding time T.

Input:
Integers n and T
Then n lines: time value

Output:
Maximum value achievable

! Constraints (suggested):
! - 1 ≤ n ≤ 2000
! - 1 ≤ T ≤ 5000
! - 1 ≤ time[i] ≤ T
! - 1 ≤ value[i] ≤ 10^6

Example Modules:
(time=3, value=4), (time=4, value=5), (time=7, value=10) with T=10
Output: 14 (take modules 1 and 3: time 3+7=10, value 4+10=14)

? Notes
? A brute force subset search is infeasible.
? Your solution should handle the full constraints.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

long long calculateMax(vector<int> &t, vector<ll> &v, int T)
{
  int n = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(T + 1, 0));

  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < T + 1; j++)
    {
      int current = dp[i][j] = dp[i - 1][j];

      if (t[i - 1] <= j)
      {
        int included = dp[i - 1][j - t[i - 1]] + v[i - 1];
        dp[i][j] = max(current, included);
      }
    }
  }

  return dp[n][T];
}

int main()
{

  ios::sync_with_stdio(false);

  cin.tie(nullptr);

  int n, T;

  cin >> n >> T;

  vector<int> t(n);

  vector<ll> v(n);

  for (int i = 0; i < n; i++)
  {

    cin >> t[i] >> v[i];
  }

  ll best = calculateMax(t, v, T);

  cout << best << "\n";

  return 0;
}