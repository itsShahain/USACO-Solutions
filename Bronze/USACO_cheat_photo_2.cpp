#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;
using ll = long long;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nl '\n'
#define RUNTIME
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
  vector<int> a(N);
  vector<int> b(N);
  for (auto &data : a)
    cin >> data;
  for (auto &data : b)
    cin >> data;
  int in_place = 0;
  int found_at;
  auto find = [&](int x, int from)
  {
    found_at = -1;
    for (int j = from; j < (int)b.size(); j++)
      if (b[j] == x)
      {
        found_at = j;
        return;
      }
  };
  int prev_pos = -1;
  for (int i = 0; i < (int)a.size(); i++)
  {
    find(a[i], prev_pos + 1);
    if (found_at > prev_pos)
    {
      in_place++;
      prev_pos = found_at;
    }
  }
  cout << N - in_place << nl;
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