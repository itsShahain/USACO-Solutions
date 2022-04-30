//Nick Wu's Solution in c++
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

vector<int> have;
vector<vector<int>> constituents;

bool canMake(int metal)
{
  if (have[metal])
  {
    have[metal]--;
    return true;
  }
  if (constituents[metal].size() == 0)
    return false;
  for (auto &constituent : constituents[metal])
  {
    if (!canMake(constituent))
      return false;
  }
  return true;
};

void solve()
{
  int N;
  cin >> N;
  constituents.resize(N);
  have.resize(N);
  for (auto &data : have)
    cin >> data;
  int K;
  cin >> K;
  while (K--)
  {
    int metal, M, constituent;
    cin >> metal >> M;
    metal--;
    while (M--)
    {
      cin >> constituent;
      constituent--;
      constituents[metal].push_back(constituent);
    }
  }
  int ans = 0;
  while (canMake(N - 1))
    ans++;
  cout << ans;
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