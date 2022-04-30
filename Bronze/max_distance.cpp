#include <bits/stdc++.h>
using namespace std;

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
  // setIO("prob");
  int N;
  scanf("%d", &N);
  vector<pair<int, int>> points(N);
  for (int i = 0; i < N; i++)
  {
    int coordX;
    scanf("%d", &coordX);
    points[i].first = coordX;
  }
  for (int i = 0; i < N; i++)
  {
    int coordY;
    scanf("%d", &coordY);
    points[i].second = coordY;
  }

  sort(points.begin(), points.end());
  int ans;
  for (int i = 0; i < (int)points.size(); i++)
  {
    for (int j = i + 1; j < (int)points.size(); j++)
    {
      ans = max((double)ans, pow((points[i].first - points[j].first), 2) + pow(points[i].second - points[j].second, 2));
    }
  }
  printf("%d", ans);
}