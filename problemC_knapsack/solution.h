#pragma once
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// Returns the maximum value achievable with time budget T,
// given modules with costs t[] and values v[]. Each module usable at most once.
ll calculateMax(const vector<int> &t, const vector<ll> &v, int T)
{
  int n = t.size();
  vector<vector<ll>> dp(n + 1, vector<ll>(T + 1, 0));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= T; j++)
    {
      dp[i][j] = dp[i - 1][j];
      if (t[i - 1] <= j)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - t[i - 1]] + v[i - 1]);
    }
  }
  return dp[n][T];
}
