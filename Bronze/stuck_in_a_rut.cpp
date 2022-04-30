#include <bits/stdc++.h>
using namespace std;

struct cowNorth
{
  int id;
  long long x, y, eaten = 1e10;
  bool operator<(struct cowNorth &c)
  {
    return x < c.x;
  }
};

struct cowEast
{
  int id;
  long long x, y, eaten;
  bool operator<(struct cowEast &c)
  {
    return y < c.y;
  }
};

int main()
{
  const long long INF = 1e10;
  long long N, id = -1;
  char Direction;
  vector<struct cowNorth> northCows;
  vector<struct cowEast> eastCows;
  scanf("%lld", &N);
  while (N--)
  {
    id++;
    scanf(" %c", &Direction);
    if (Direction == 'N')
    {
      struct cowNorth cow;
      scanf("%lld", &cow.x);
      scanf("%lld", &cow.y);
      cow.id = id;
      northCows.push_back(cow);
    }
    else
    {
      struct cowEast cow;
      scanf("%lld", &cow.x);
      scanf("%lld", &cow.y);
      cow.id = id;
      eastCows.push_back(cow);
    }
  }
  sort(northCows.begin(), northCows.end());
  sort(eastCows.begin(), eastCows.end());

  for (auto &dataN : northCows)
  {
    for (auto &dataE : eastCows)
    {
      if (dataN.x <= dataE.x || dataN.y >= dataE.y)
      {
        dataN.eaten = min(INF, dataN.eaten);
        dataE.eaten = min(INF, dataE.eaten);
      }
      else if ((dataN.x - dataE.x) == (dataE.y - dataN.y))
      {
        dataN.eaten = min(INF, dataN.eaten);
        dataE.eaten = min(INF, dataE.eaten);
      }

      else if ((dataN.x - dataE.x) < (dataE.y - dataN.y))
      {
        if (dataN.eaten < INF || dataE.eaten < INF)
        {
          /*pass*/
        }
        else
        {
          dataE.eaten = min(INF, dataE.eaten);
          dataN.eaten = min(dataE.y - dataN.y, dataN.eaten);
        }
      }
      else
      {
        if (dataN.eaten < INF || dataE.eaten < INF)
        {
          /*pass*/
        }
        else
        {
          dataN.eaten = min(INF, dataN.eaten);
          dataE.eaten = min((dataN.x - dataE.x), dataE.eaten);
        }
      }
    }
  }
  // cout << "asd";
  vector<pair<int, long long>> tempStore;

  for (auto data : northCows)
  {
    tempStore.push_back({data.id, data.eaten});
  }
  for (auto data : eastCows)
  {
    tempStore.push_back({data.id, data.eaten});
  }

  sort(tempStore.begin(), tempStore.end());
  for (auto data : tempStore)
  {
    if (data.second == INF)
    {
      printf("Infinity\n");
    }
    else
    {
      printf("%lld\n", data.second);
    }
  }
}