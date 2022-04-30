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
  int G = 0, Y = 0;
  vector<string> correct(3);
  vector<string> guess(3);
  for (auto &data : correct)
    cin >> data;
  for (auto &data : guess)
    cin >> data;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (correct[i][j] == guess[i][j])
      {
        G++;
        correct[i][j] = guess[i][j] = 'x';
      }
  cout << G << nl;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
        for (int l = 0; l < 3; l++)
          if (correct[i][j] == guess[k][l] && correct[i][j] != 'x' && guess[k][l] != 'x')
          {
            Y++;
            correct[i][j] = guess[k][l] = 'x';
          }

  cout << Y << nl;
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