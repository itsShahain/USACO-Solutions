#include "bits/stdc++.h"
// Fusion of my orginal idea and Benq's idea to use a set to
// avoid dupliacte adjacent pairs.
// Here is an adjPair :
// CG
// .C
// Basically adjPair forms an 'L' shape with 2C's and 1G at the "center"
// Whereas the following is not an adjPair
// CGC
// This is an opposing pair

// My idea here is that if there is a patch of grass, first check if it is a part of an opposing pair
/* 
   If it is an opposing pair, then really just increment the answer by one.
   Why? Because these two cows can only meet through this opposing pair. So if there is opposing pair
   AND an adjPair at the same grass patch it is always optimal to use the opposing pair, since these two cows of the opposing pair
   can only meet once forever using the patch of grass that makes up the opposing pair.
   
   Why not use the adjPair over an opposing pair if they are both at the same grass patch?
   Because the cows of the adjPair can also meet sometime in the future! Check out the following example:
   CGC
   .CG

   Hope you understand!
   God Bless You!

   Best Regards,
   Shahain.
   
*/ 
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

void solve()
{
  int N, M;
  cin >> N >> M;
  char pasture[N + 2][M + 2];
  set<vector<pair<int, int>>> adjPairs;
  for (int row = 0; row < N + 2; row++)
  {
    for (int col = 0; col < M + 2; col++)
    {
      if (row == 0 || row == N + 1)
      {
        pasture[row][col] = '.';
      }
      else if (col == 0 || col == M + 1)
      {
        pasture[row][col] = '.';
      }
      else
      {
        cin >> pasture[row][col];
      }
    }
  }
  int ans = 0;
  for (int row = 0; row < N + 2; row++)
  {
    for (int col = 0; col < M + 2; col++)
    {
      if (pasture[row][col] == 'G')
      {
        if ((pasture[row - 1][col] == 'C' && pasture[row + 1][col] == 'C') ||
            (pasture[row][col + 1] == 'C' && pasture[row][col - 1] == 'C'))
        {
          ans++;
          continue;
        }
        else
        {
          vector<pair<int, int>> adjPair;
          if (pasture[row - 1][col] == 'C' && pasture[row][col + 1] == 'C')
          {
            adjPair.push_back({row - 1, col});
            adjPair.push_back({row, col + 1});
            sort(all(adjPair));
            adjPairs.insert(adjPair);
          }
          else if (pasture[row][col + 1] == 'C' && pasture[row + 1][col] == 'C')
          {
            adjPair.push_back({row, col + 1});
            adjPair.push_back({row + 1, col});
            sort(all(adjPair));
            adjPairs.insert(adjPair);
          }
          else if (pasture[row + 1][col] == 'C' && pasture[row][col - 1] == 'C')
          {
            adjPair.push_back({row + 1, col});
            adjPair.push_back({row, col - 1});
            sort(all(adjPair));
            adjPairs.insert(adjPair);
          }
          else if (pasture[row][col - 1] == 'C' && pasture[row - 1][col] == 'C')
          {
            adjPair.push_back({row, col - 1});
            adjPair.push_back({row - 1, col});
            sort(all(adjPair));
            adjPairs.insert(adjPair);
          }
        }
      }
    }
  }
  cout << ans + adjPairs.size();
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