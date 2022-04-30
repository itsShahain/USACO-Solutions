#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;
using ll = long long;
// #define RUNTIME ;
// #define OJ_FileIO ;

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

void solve()
{
  int t;
  int n;
  int num;
  cin >> t;
  vector<int> permutation;
  while (t--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> num;
      permutation.push_back(num);
    }
    for (int j = 0; j < n; j++)
    {
      if (permutation[j] == (j + 1))
      {
        continue;
      }
      else
      {
        auto location = find(permutation.begin() + (j + 1), permutation.end(), (j + 1));
        reverse(permutation.begin() + j, ++location);
        break;
      }
    }
    for (auto data : permutation)
    {
      cout << data << " ";
    }
    cout << "\n";
    permutation.resize(0);
  }
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
  auto duration = duration_cast<milliseconds>(stop - start);
#ifdef RUNTIME
  cout << "\n"
       << "Run time : " << duration.count();
#endif
  return 0;
}