#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nl '\n'
// #define RUNTIME ;
// #define OJ_FileIO ;

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int grid[150][150];
int N, M, K;
bool visited[150][150]{false};
int covered;
int count;
void spirale(int direction, int sense, int row, int col)
{
  visited[row][col] = true;
  if (covered == N * M)
  {
    return;
  }

  ::count++;
  if (row >= 49 && row <= 48 + N && col >= 49 && col <= 48 + M)
  {
    covered++;
  }
  switch (direction)
  {
  case 0:
    grid[row][col] = min(grid[row][col], ::count);
    if (sense == 0)
    {
      if (!visited[row][col + 1])
      {
        spirale(1, sense, row, col + 1);
      }
      else
      {
        spirale(0, sense, row - 1, col);
      }
    }
    else
    {
      if (!visited[row][col - 1])
      {
        spirale(3, sense, row, col - 1);
      }
      else
      {
        spirale(0, sense, row - 1, col);
      }
    }
    break;
  case 1:
    grid[row][col] = min(grid[row][col], ::count);
    if (sense == 0)
    {
      if (!visited[row + 1][col])
      {
        spirale(2, sense, row + 1, col);
      }
      else
      {
        spirale(1, sense, row, col + 1);
      }
    }
    else
    {
      if (!visited[row - 1][col])
      {
        spirale(0, sense, row - 1, col);
      }
      else
      {
        spirale(1, sense, row, col + 1);
      }
    }
    break;
  case 2:
    grid[row][col] = min(grid[row][col], ::count);
    if (sense == 0)
    {
      if (!visited[row][col - 1])
      {
        spirale(3, sense, row, col - 1);
      }
      else
      {
        spirale(2, sense, row + 1, col);
      }
    }
    else
    {
      if (!visited[row][col + 1])
      {
        spirale(1, sense, row, col + 1);
      }
      else
      {
        spirale(2, sense, row + 1, col);
      }
    }
    break;
  case 3:
    grid[row][col] = min(grid[row][col], ::count);
    if (sense == 0)
    {
      if (!visited[row - 1][col])
      {
        spirale(0, sense, row - 1, col);
      }
      else
      {
        spirale(3, sense, row, col - 1);
      }
    }
    else
    {
      if (!visited[row + 1][col])
      {
        spirale(2, sense, row + 1, col);
      }
      else
      {
        spirale(3, sense, row, col - 1);
      }
    }
    break;
  default:
    break;
  }
}

void solve()
{
  cin >> N >> M >> K;
  int row, col, T;
  for (auto &rowInit : grid)
  {
    for (auto &colInit : rowInit)
    {
      colInit = INT32_MAX;
    }
  }
  for (int i = 0; i < K; i++)
  {
    for (auto &rowInit : visited)
    {
      for (auto &colInit : rowInit)
      {
        colInit = false;
      }
    }
    cin >> row >> col >> T;
    row--;
    col--;
    grid[49 + row][49 + col] = 1;
    visited[49 + row][49 + col] = true;
    ::count = 1;
    covered = 1;
    spirale(0, T, 48 + row, 49 + col);
  }
  for (int rowCheck = 49; rowCheck <= 48 + N; rowCheck++)
  {
    for (int colCheck = 49; colCheck <= 48 + M; colCheck++)
    {
      cout << grid[rowCheck][colCheck] << ' ';
    }
    cout << nl;
  }
}

int main()
{
  auto start = high_resolution_clock::now();
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef OJ_FileIO
  setIO("prob");
#endif
  solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
#ifdef RUNTIME
  cout << "\n"
       << "Run time : " << duration.count() << " microseconds";
#endif
  return 0;
}