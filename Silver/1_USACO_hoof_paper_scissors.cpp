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
  char state;
  cin >> N;
  int Prefix[N + 1][3]{0};
  for (int i = 1; i <= N; i++)
  {
    cin >> state;
    Prefix[i][0] = Prefix[i - 1][0] + (int)(state == 'P');
    Prefix[i][1] = Prefix[i - 1][1] + (int)(state == 'H');
    Prefix[i][2] = Prefix[i - 1][2] + (int)(state == 'S');
  }
  int ans = INT32_MIN;
  for (int i = 1; i <= N - 1; i++)
  {
    ans = max(ans, max({Prefix[i][0], Prefix[i][1], Prefix[i][2]}) + max({Prefix[N][0] - Prefix[i][0], Prefix[N][1] - Prefix[i][1], Prefix[N][2] - Prefix[i][2]}));
  }
  cout << ans << nl;
}

int main()
{
  auto start = high_resolution_clock::now();
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef OJ_FileIO
  setIO("hps");
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