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
  int N;
  cin >> N;
  vector<ll> cows(N);
  for (auto &data : cows)
    cin >> data;
  vector<ll> prefix_sum((int)cows.size() + 1);
  prefix_sum[0] = 0;
  partial_sum(all(cows), prefix_sum.begin() + 1);
  ll ans = INT64_MIN;
  for (auto &data : prefix_sum)
    data %= 7;
  for (int mod = 0; mod < 6; mod++)
  {
    int minimum = INT32_MAX, maximum = INT32_MIN;
    for (int i = 0; i < N + 1; i++)
    {
      if (prefix_sum[i] == mod)
      {
        maximum = max(maximum, i);
        minimum = min(minimum, i);
      }
    }
    ans = max(ans, (ll)maximum - minimum);
  }

  cout << ans << nl;
}

int main()
{
  auto start = high_resolution_clock::now();
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef OJ_FileIO
  setIO("div7");
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