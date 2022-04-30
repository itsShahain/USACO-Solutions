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
  const int MAX = 1000;
  int N, K;
  cin >> N >> K;
  int a1, a2, b1, b2;
  int wall[MAX + 2][MAX + 2]{0};
  for (int i = 0; i < N; i++)
  {
    cin >> a1 >> a2 >> b1 >> b2;
    a1++;
    a2++;
    b1++;
    b2++;
    for (int k = a2; k < b2; k++)
    {
      wall[k][a1]++;
      wall[k][b1]--;
    }
  }
  for (int i = 1; i <= 1001; i++)
  {
    for (int j = 1; j <= 1001; j++)
    {
      wall[i][j] += wall[i][j - 1];
    }
  }
  int ans = 0;
  for (auto &row : wall)
  {
    for (auto &col : row)
    {
      ans += (int)(col == K);
    }
  }
  cout << ans;
}

int main()
{
  auto start = high_resolution_clock::now();
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef OJ_FileIO
  setIO("paintbarn");
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