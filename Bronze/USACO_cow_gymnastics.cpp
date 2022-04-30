#include <bits/stdc++.h>
using namespace std;

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
  setIO("gymnastics");
  pair<bool, int> arr[20][20]{};
  int K, N;
  scanf("%d%d", &K, &N);
  vector<int> init;
  for (int i = 0; i < N; i++)
  {
    int cowNum;
    scanf("%d", &cowNum);
    init.push_back(cowNum);
  }
  for (int i = 0; i < (int)init.size(); i++)
  {
    for (int j = i + 1; j < (int)init.size(); j++)
    {
      arr[init[i]-1][init[j]-1].first = true;
      arr[init[i]-1][init[j]-1].second++;
    }
  }

  for (int i = 0; i < K - 1; i++)
  {
    init.resize(0);
    for (int a = 0; a < N; a++)
    {
      int cowNum;
      scanf("%d", &cowNum);
      init.push_back(cowNum);
    }
    for (int a = 0; a < (int)init.size(); a++)
    {
      for (int b = a + 1; b < (int)init.size(); b++)
      {
        if (arr[init[a]-1][init[b]-1].first)
        {
          arr[init[a]-1][init[b]-1].second++;
        }
      }
    }
  }
  int pairs = 0;
  for (int row = 0; row < 20; row++)
  {
    for (int col = 0; col < 20; col++)
    {
      if (arr[row][col].second == K)
      {
        pairs++;
      }
    }
  }
  cout << pairs;
}
