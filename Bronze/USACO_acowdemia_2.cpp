#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;
using ll = long long;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nl '\n'
#define RUNTIME ;
#define OJ_FileIO ;

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

void solve()
{
  int K, N;
  cin >> K >> N;
  vector<string> names(N);
  vector<vector<char>> status(N);
  vector<char> chstore;
  for (int i = 0; i < N; i++)
  {
    chstore.resize(0);
    for (int j = 0; j < N; j++)
    {
      chstore.push_back('?');
    }
    status[i] = chstore;
  }

  map<string, int> transpose;
  int count = 0;
  for (auto &data : names)
  {
    cin >> data;
    transpose[data] = count;
    count++;
  }
  vector<string> temp(N);
  for (int k = 0; k < K; k++)
  {
    for (auto &data : temp)
    {
      cin >> data;
    }
    bool skip = false;
    for (int i = 0; i < (int)temp.size() - 1; i++)
    {
      if (temp[i] < temp[i + 1])
      {
        continue;
      }
      else
      {
        skip = false;
        for (int z = i + 1; z < (int)temp.size(); z++)
        {
          status[transpose[temp[z]]][transpose[temp[z]]] = 'B';
          for (int j = i; j >= 0; j--)
          {
            status[transpose[temp[z]]][transpose[temp[j]]] = '1';
            status[transpose[temp[j]]][transpose[temp[j]]] = 'B';
            status[transpose[temp[j]]][transpose[temp[z]]] = '0';
          }
        }
      }
    }
  }
  for (auto &row : status)
  {
    for (auto &cow : row)
    {
      cout << cow;
    }
    cout << nl;
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
  auto duration = duration_cast<microseconds>(stop - start);
#ifdef RUNTIME
  cout << "\n"
       << "Run time : " << duration.count() << " microseconds";
#endif
  return 0;
}