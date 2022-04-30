// This is not an easy problem at all (this is VERY HARD), so don't be discouraged if you have not understood the solution. Here is a link that will definitely help you understand the solution better, even I was struggling but now I understand the solution. Don't give up, keep pushing.
// https://math.stackexchange.com/questions/732679/how-to-rotate-a-matrix-by-45-degrees#:~:text=The%20formula%20of%20this%20rotation,row%20and%20the%20fourth%20column.
#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;
using ll = long long;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nl '\n'
// #define RUNTIME
#define OJ_FileIO

#ifdef OJ_FileIO
void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
#endif

void solve()
{
  int farm[801][801]{0};
  int N, K;
  cin >> N >> K;
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      cin >> farm[i + j - 1][-i + j + N];
    }
  }
  int prefix[801][801]{0};
  for (int i = 1; i <= 800; i++)
  {
    for (int j = 1; j <= 800; j++)
    {
      prefix[i][j] = farm[i][j] + prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
    }
  }
  int mx = INT32_MIN;
  int sm;
  K = 2 * K + 1;
  for (int i = 1; i <= 800; i++)
  {
    for (int j = 1; j <= 800; j++)
    {
      //The easier way to check for non-lattice positions.
      // If in doubt check this small video for an inspiration (look around 0:10): https://youtu.be/U4ogK0MIzqk 
      // And then compare to https://math.stackexchange.com/questions/732679/how-to-rotate-a-matrix-by-45-degrees#:~:text=The%20formula%20of%20this%20rotation,row%20and%20the%20fourth%20column.
      if (N % 2 == 1 && (i + j) % 2 == 0)
      {
        sm = prefix[i][j] - prefix[max(i - K, 0)][j] - prefix[i][max(j - K, 0)] + prefix[max(i - K, 0)][max(j - K, 0)];
        mx = max(mx, sm);
      }
      else if (N % 2 == 0 && (i + j) % 2 == 1)
      {
        sm = prefix[i][j] - prefix[max(i - K, 0)][j] - prefix[i][max(j - K, 0)] + prefix[max(i - K, 0)][max(j - K, 0)];
        mx = max(mx, sm);
      }
    }
  }
  cout << mx << nl;
}

int main()
{
  auto start = high_resolution_clock::now();
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef OJ_FileIO
  setIO("lazy");
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