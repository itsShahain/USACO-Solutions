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
  int N, x;
  cin >> N;
  vector<int> b(N - 1);
  for (auto &data : b)
    cin >> data;
  set<int> used;
  vector<int> a;
  for (int i = 1; i <= N; i++)
  {
    bool ok = true;
    used.clear();
    a.resize(0);
    used.insert(i);
    a.push_back(i);
    x = i;
    for (int j = 0; j < N - 1; j++)
    {
      x = b[j] - x;
      if (x <= 0 || used.count(x) == 1)
      {
        ok = false;
        break;
      }
      used.insert(x);
      a.push_back(x);
    }
    if (ok)
    {
      for (int k = 0; k < N; k++)
      {
        cout << a[k];
        if (k != N - 1)
          cout << " ";
      }

      return;
    }
  }
}

int main()
{
  auto start = high_resolution_clock::now();
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef OJ_FileIO
  setIO("photo");
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