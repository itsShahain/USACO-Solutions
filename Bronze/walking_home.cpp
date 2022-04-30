// Backtracking solution
#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;
using ll = long long;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nl '\n'
// #define RUNTIME
// #define OJ_FileIO

int N, K, ans;
vector<vector<bool>> grid;

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

void backtrack(int row, int col, char direction, int changes)
{
  if (changes > K)
    return;
  if (changes == K)
  {
    if (direction == 'D')
    {
      if (col != N)
      {
        return;
      }
    }
    else
    {
      if (row != N)
      {
        return;
      }
    }
  }
  if (row == N && col == N)
    ans++;
  else
  {
    if (grid[row + 1][col])
    {
      if (direction == 'X')
      {
        backtrack(row + 1, col, 'D', changes);
      }
      else
      {
        if (direction != 'D')
          backtrack(row + 1, col, 'D', changes + 1);
        else
          backtrack(row + 1, col, 'D', changes);
      }
    }
    if (grid[row][col + 1])
    {
      if (direction == 'X')
      {
        backtrack(row, col + 1, 'R', changes);
      }
      else
      {
        if (direction != 'R')
          backtrack(row, col + 1, 'R', changes + 1);
        else
          backtrack(row, col + 1, 'R', changes);
      }
    }
  }
}

void solve()
{
  cin >> N >> K;
  for (int row = 0; row < N + 2; row++)
  {
    vector<bool> v;
    for (int col = 0; col < N + 2; col++)
    {
      v.push_back(false);
    }
    grid.push_back(v);
  }

  char cell;
  for (int row = 1; row < N + 1; row++)
  {
    for (int col = 1; col < N + 1; col++)
    {
      cin >> cell;
      if (cell == '.')
        grid[row][col] = true;
      else
        grid[row][col] = false;
    }
  }
  // X just indicates that we are just starting off.
  backtrack(1, 1, 'X', 0);

  cout << ans << nl;
}

int main()
{
  auto start = high_resolution_clock::now();
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef OJ_FileIO
  setIO("prob");
#endif
  int t;
  cin >> t;
  while (t--)
  {
    ans = 0;
    grid.resize(0);
    solve();
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
#ifdef RUNTIME
  cout << "\n"
       << "Run time : " << duration.count() << " microseconds";
#endif
  return 0;
}