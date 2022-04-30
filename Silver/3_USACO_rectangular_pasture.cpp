#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;
using ll = long long;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nl '\n'
// #define RUNTIME
// #define OJ_FileIO

#ifdef OJ_FileIO
void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
#endif

pair<ll, ll> point;
vector<pair<ll, ll>> points;
int prefix[2501][2501];
int grid[2501][2501];

bool ycomp(pair<ll, ll> p1, pair<ll, ll> p2)
{
  return p1.second < p2.second;
}

void solve()
{
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> point.first >> point.second;
    points.push_back(point);
  }
  sort(all(points));
  for (int i = 0; i < N; i++)
  {
    points[i].first = i + 1;
  }
  sort(all(points), ycomp);
  for (int i = 0; i < N; i++)
  {
    points[i].second = i + 1;
  }
  for (auto &data : points)
  {
    grid[data.second][data.first] = 1;
  }
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      prefix[i][j] = grid[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
    }
  }
  ll ans = 0;
  auto rsum = [&](int x1, int y1, int x2, int y2)
  {
    return prefix[y2][x2] - prefix[y2][x1 - 1] - prefix[y1 - 1][x2] + prefix[y1 - 1][x1 - 1];
  };
  for (int i = 0; i < N; i++)
  {
    for (int j = i; j < N; j++)
    {
      int x1 = min(points[i].first, points[j].first);
      int x2 = max(points[i].first, points[j].first);
      ans += rsum(1, i + 1, x1, j + 1) * rsum(x2, i + 1, N, j + 1);
    }
  }
  ans++;
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
  solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
#ifdef RUNTIME
  cout << "\n"
       << "Run time : " << duration.count() << " microseconds";
#endif
  return 0;
}