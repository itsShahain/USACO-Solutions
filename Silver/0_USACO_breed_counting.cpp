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
  int N, Q;
  cin >> N >> Q;
  vector<int> cows(N);
  vector<int> H, G, J;
  H.push_back(0);
  G.push_back(0);
  J.push_back(0);
  for (auto &data : cows)
    cin >> data;
  for (int i = 0; i < (int)cows.size(); i++)
  {
    if (cows[i] == 1)
    {
      H.push_back(H[i] + 1);
      G.push_back(G[i]);
      J.push_back(J[i]);
    }
    if (cows[i] == 2)
    {
      G.push_back(G[i] + 1);
      H.push_back(H[i]);
      J.push_back(J[i]);
    }
    if (cows[i] == 3)
    {
      J.push_back(J[i] + 1);
      G.push_back(G[i]);
      H.push_back(H[i]);
    }
  }
  while (Q--)
  {
    int a, b;
    cin >> a >> b;
    cout << H[b] - H[a - 1] << " " << G[b] - G[a - 1] << " " << J[b] - J[a - 1] << nl;
  }
}

int main()
{
  auto start = high_resolution_clock::now();
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef OJ_FileIO
  setIO("bcount");
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