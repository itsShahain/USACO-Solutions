#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;
using ll = long long;
#define RUNTIME ;
#define OJ_FileIO ;

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

void solve()
{
  int N;
  cin >> N;
  string S;
  cin >> S;
  set<string> currentStr;
  int ans = INT32_MAX;
  for (int len = 1; len < N; len++)
  {
    bool OK = true;
    for (int i = 0; i < N; i++)
    {
      if (currentStr.find(S.substr(i, len)) == currentStr.end())
      {
        currentStr.insert(S.substr(i, len));
      }
      else
      {
        OK = false;
        break;
      }
    }

    if (OK)
    {
      ans = min(ans, len);
    }
    currentStr.clear();
  }
  cout << ans;
}

int main()
{
  auto start = high_resolution_clock::now();
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef OJ_FileIO
  setIO("whereami");
#endif
  solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
#ifdef RUNTIME
  cout << "\n"
       << "Run time : " << duration.count();
#endif
  return 0;
}