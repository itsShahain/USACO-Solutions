#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;
using ll = long long;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nl '\n'
// #define RUNTIME
#define OJ_FileIO

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

void solve()
{
  int N, K, B, broken;
  cin >> N >> K >> B;
  vector<bool> state(N, true);
  int ans = INT32_MAX;
  while (B--)
  {
    cin >> broken;
    broken--;
    state[broken] = false;
  }
  vector<int> prefix(N + 1, 0);
  for (int i = 0; i < N; i++)
  {
    prefix[i + 1] = prefix[i] + (int)state[i];
  }

  for (int i = 0; i <= N - K; i++)
  {
    ans = min(ans, K - (prefix[i + K] - prefix[i]));
  }
  cout << ans << nl;
}

int main()
{
  auto start = high_resolution_clock::now();
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef OJ_FileIO
  setIO("maxcross");
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