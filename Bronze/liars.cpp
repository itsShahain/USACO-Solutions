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
  int N, x;
  cin >> N;
  char mag;
  vector<pair<int, int>> pos;
  vector<pair<char, int>> op;
  for (int i = 0; i < N; i++)
  {
    cin >> mag >> x;
    op.push_back({mag, x});
    pos.push_back({x, 0});
  }
  sort(all(pos));
  int mxcount = INT32_MIN;
  for (auto &data : op)

    if (data.first == 'G')
    {
      for (int j = 0; j < (int)pos.size(); j++)
        if (pos[j].first >= data.second)
        {
          pos[j].second++;
          mxcount = max(mxcount, pos[j].second);
        }
    }
    else
    {
      for (int j = (int)pos.size() - 1; j >= 0; j--)
        if (pos[j].first <= data.second)
        {
          pos[j].second++;
          mxcount = max(mxcount, pos[j].second);
        }
    }

  cout << N - mxcount;
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