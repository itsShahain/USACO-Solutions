#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int visitedSQ = 1;
int paths = 0;
int n = 7;
bool visited[9][9];
string pathStr = "";
char direction;

bool split_scan_horizontal(int row, int col)
{
  if (visited[row + 1][col] || visited[row - 1][col])
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool split_scan_vertical(int row, int col)
{

  if (visited[row][col + 1] || visited[row][col - 1])
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool grid_split(int nnRow, int nnCol, int nRow, int nCol)
{
  if (visited[nnRow][nnCol])
  {
    if (direction == 'R' || direction == 'L')
    {
      if (!split_scan_horizontal(nRow, nCol))
      {
        return false;
      }
    }
    if (direction == 'U' || direction == 'D')
    {
      if (!split_scan_vertical(nRow, nCol))
      {
        return false;
      }
    }
  }
  return true;
}

bool can_traverse(int row, int col)
{

  if (visited[row][col])
    return false;

  return true;
}

void backtrack(int row, int col)
{

  if (row == (n) && col == (n))
  {
    if (visitedSQ == n * n)
    {
      paths++;
    }
  }
  else
  {
    for (int d = 0; d < 4; d++)
    {
      int nRow, nnRow;
      int nCol, nnCol;
      switch (d)
      {
      case 0:
        nRow = row + 1;
        nCol = col;
        nnRow = nRow + 1;
        nnCol = nCol;
        direction = 'D';
        break;
      case 1:
        nRow = row;
        nCol = col + 1;
        nnRow = nRow;
        nnCol = nCol + 1;
        direction = 'R';

        break;
      case 2:
        nRow = row - 1;
        nCol = col;
        nnRow = nRow - 1;
        nnCol = nCol;
        direction = 'U';

        break;
      case 3:
        nRow = row;
        nCol = col - 1;
        nnRow = nRow;
        nnCol = nCol - 1;
        direction = 'L';

        break;
      }
      if (can_traverse(nRow, nCol) && grid_split(nnRow, nnCol, nRow, nCol))
      {
        visited[nRow][nCol] = true;
        visitedSQ++;
        backtrack(nRow, nCol);
        visited[nRow][nCol] = false;
        visitedSQ--;
      }
    }
  }
}

int main()
{
  auto start = high_resolution_clock::now();
  ios::sync_with_stdio(false);
  cin.tie(0);
  setIO("prob");
  for (int row = 0; row < 9; row++)
  {
    for (int col = 0; col < 9; col++)
    {
      visited[row][col] = true;
    }
  }
  for (int row = 1; row < 8; row++)
  {
    for (int col = 1; col < 8; col++)
    {
      visited[row][col] = false;
    }
  }

  visited[1][1] = true;
  backtrack(1, 1);
  cout << paths << "\n";
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  cout << "Run time : " << duration.count();

  return 0;
}
