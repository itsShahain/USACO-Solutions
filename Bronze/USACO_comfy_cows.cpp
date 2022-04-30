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
  char pasture[1003][1003];
  vector<pair<int, int>> coordinates;
  for (int i = 0; i < N; i++)
  {
    pair<int, int> p;
    cin >> p.first >> p.second;
    p.first++;
    p.second++;
    coordinates.push_back(p);
    pasture[p.first][p.second] = 'C';
  }
  int ans = 0;
  for (auto &data : coordinates)
  {
    int count = 0;
    int dx[]{0, 1, 0, -1};
    int dy[]{-1, 0, 1, 0};

    for (int j = 0; j < 4; j++)
      if (pasture[data.first + dx[j]][data.second + dy[j]] == 'C')
        count++;

    if (count == 3)
      ans++;
  }
  vector<int> answers;
  answers.push_back(ans);
  reverse(all(coordinates));
  for (auto &data : coordinates)
  {
    int count = 0;
    int dx[]{0, 1, 0, -1};
    int dy[]{-1, 0, 1, 0};

    for (int j = 0; j < 4; j++)
      if (pasture[data.first + dx[j]][data.second + dy[j]] == 'C')
        count++;

    if (count == 3)
      ans--;

    for (int j = 0; j < 4; j++)
      if (pasture[data.first + dx[j]][data.second + dy[j]] == 'C')
      {
        count = 0;
        for (int k = 0; k < 4; k++)
          if (pasture[data.first + dx[j] + dx[k]][data.second + dy[j] + dy[k]] == 'C')
            count++;
        if (count == 3)
          ans--;
        if (count == 4)
          ans++;
      }

    answers.push_back(ans);
    pasture[data.first][data.second] = '0';
  }
  for (int i = (int)answers.size() - 2; i >= 0; i--)
  {
    cout << answers[i] << nl;
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