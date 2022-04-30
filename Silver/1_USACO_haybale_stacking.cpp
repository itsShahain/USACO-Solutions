#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;
using ll = long long;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nl '\n'
// #define RUNTIME
// #define OJ_FileIO

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

void solve()
{
  int N, K, a, b;
  cin >> N >> K;
  vector<int> diff(N + 1, 0);
  while (K--)
  {
    cin >> a >> b;
    diff[a - 1]++;
    diff[b]--;
  }
  vector<int> haybales(N, 0);
  partial_sum(diff.begin(), diff.end() - 2, haybales.begin());
  sort(all(haybales));
  cout << haybales[((N + 1) / 2) - 1] << nl;
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