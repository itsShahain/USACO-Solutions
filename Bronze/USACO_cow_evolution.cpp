#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;
using ll = long long;
// #define RUNTIME ;
#define OJ_FileIO ;

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

void solve()
{
  int N, K;
  string characteristic;
  cin >> N;
  set<string> characteristics;
  vector<string> populations[N];
  for (int i = 0; i < N; i++)
  {
    cin >> K;
    for (int j = 0; j < K; j++)
    {
      cin >> characteristic;
      characteristics.insert(characteristic);
      populations[i].push_back(characteristic);
    }
  }
  for (auto it = characteristics.begin(); it != characteristics.end(); it++)
  {
    bool A = false, B = false, AB = false;
    for (auto it2 = next(it); it2 != characteristics.end(); it2++)
    {
      A = false, B = false, AB = false;
      for (auto data : populations)
      {
        if (find(data.begin(), data.end(), *it) != data.end() && find(data.begin(), data.end(), *it2) != data.end())
        {
          AB = true;
        }
        else if (find(data.begin(), data.end(), *it) != data.end())
        {
          A = true;
        }
        else if (find(data.begin(), data.end(), *it2) != data.end())
        {
          B = true;
        }
      }
      bool Check = A && B && AB;
      if (Check)
      {
        cout << "no";
        return;
      }
    }
  }
  cout << "yes";
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