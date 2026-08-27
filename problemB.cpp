/*
* Problem B — “Minimum Meeting Rooms (Scheduling)”
* You are given m meetings, each with a start time and an end time: (s_i, e_i) with s_i < e_i. A room can host only one meeting at a time.

TODO: Compute the minimum number of rooms required to schedule all meetings.

Input:
- Integer m
- Then m lines: start end

Output:
Minimum number of rooms needed

! Constraints (suggested):
! - 1 ≤ m ≤ 2 * 10^5
! - Times are integers (e.g., minutes) in range [0, 10^9]

Example Meetings:
(0, 30), (5, 10), (15, 20)
Output: 2

* Clarifications
* If one meeting ends at time t and another starts at time t, they do not overlap (same room is allowed).

? Notes
? Focus on an efficient approach for large m.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int calculateRooms(vector<pair<int, int>> &meetings, priority_queue<int> &heap)
{
  int n = meetings.size();
  for (int i = 0; i < n; i++)
  {
    while (!heap.empty())
    {
      if (meetings[i].second <= heap.top())
      {
        heap.pop();
      }
      else
      {
        break;
      }
    }

    heap.push(meetings[i].first);
  }
  return heap.size();
}

int main()
{

  ios::sync_with_stdio(false);

  cin.tie(nullptr);

  int m;

  cin >> m;

  vector<pair<int, int>> meetings(m);

  for (int i = 0; i < m; i++)
  {
    int s, e;

    cin >> s >> e;

    meetings[i] = {s, e};
  }

  sort(meetings.begin(), meetings.end(), [](const auto &a, const auto &b)
       { return a.second > b.second; });

  priority_queue<int> heap;

  int rooms = calculateRooms(meetings, heap);

  cout << rooms << "\n";

  return 0;
}