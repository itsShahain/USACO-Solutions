#include <bits/stdc++.h>

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
  string cowphabet;
  cin >> cowphabet;
  string herd;
  cin >> herd;
  vector<int> pos;
  int position;
  auto find_pos = [&](char letter)
  {
    for (int i = 0; i < (int)cowphabet.size(); i++)
      if (letter == cowphabet[i])
        position = i;
  };
  for (auto &data : herd)
  {
    find_pos(data);
    pos.push_back(position);
  }
  int ans = 1;
  for (int i = 1; i < (int)pos.size(); i++)
    if (pos[i] > pos[i - 1])
      continue;
    else
      ans++;

  cout << ans << nl;
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