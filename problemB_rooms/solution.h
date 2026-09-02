#pragma once
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;

// Returns the minimum number of rooms needed to schedule all meetings.
// A meeting ending at time t and another starting at t are considered non-overlapping.
int minRooms(vector<pair<ll, ll>> meetings)
{
  sort(meetings.begin(), meetings.end(), [](const auto &a, const auto &b) {
    return a.second > b.second;
  });

  priority_queue<ll> heap;
  for (auto &[s, e] : meetings)
  {
    if (!heap.empty() && e <= heap.top())
      heap.pop();
    heap.push(s);
  }
  return (int)heap.size();
}
