// In any fully enclosed polygon, the absolute value of the difference between the sum of the number of right turns and sum of the number of left turns is == 3
// What I mean here : |(total num of right turns)-(total num of left turns)| == 3
// If the number of right turns is greater than the number of left turns then the answer is CW and vice versa
// I'm using the concept of the cross-product of two MATHEMATICAL vectors (Not C++ vectors) to determine if a turn is a right or left one
// If you are not aware of the cross-product : https://youtu.be/eu6i7WJeinw
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
  int N;
  cin >> N;
  while (N--)
  {
    string str;
    cin >> str;
    int leftTurns = 0;
    int rightTurns = 0;
    int k;
    vector<int> n{0, 1};
    vector<int> e{1, 0};
    vector<int> w{-1, 0};
    vector<int> s{0, -1};
    vector<int> cd;
    vector<int> pd;
    auto turn = [&](const vector<int> &v1, const vector<int> &v2)
    {
      // Only k component of common perpendicular will differ
      k = v1[0] * v2[1] - v1[1] * v2[0];
    };
    auto transpose_direction = [&](char direction, vector<int> &d)
    {
      switch (direction)
      {
      case 'N':
        d = n;
        break;
      case 'E':
        d = e;
        break;
      case 'W':
        d = w;
        break;
      case 'S':
        d = s;
        break;
      }
    };
    for (int i = 1; i < (int)str.size(); i++)
    {
      char currDirection = str[i];
      char prevDirection = str[i - 1];
      if (currDirection == prevDirection)
        continue;
      transpose_direction(currDirection, cd);
      transpose_direction(prevDirection, pd);
      turn(pd, cd);
      if (k > 0)
      {
        leftTurns++;
      }
      else
      {
        rightTurns++;
      }
    }
    if (rightTurns > leftTurns)
    {
      cout << "CW" << nl;
    }
    else
    {
      cout << "CCW" << nl;
    }
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