#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;
using ll = long long;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nl '\n'
// #define RUNTIME
#define OJ_FileIO

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

void solve()
{
  int n;
  int area;
  cin >> n;
  vector<pair<int, int>> points(n);
  for (auto &data : points)
    cin >> data.first >> data.second;
  int ans = INT32_MIN;
  auto mod = [&](pair<int, int> a)
  {
    return sqrt((float)(a.first * a.first + a.second * a.second));
  };
  auto dot_product = [&](pair<int, int> x, pair<int, int> y)
  {
    return x.first * y.first + x.second * y.second;
  };
  auto is_right_angled = [&](int pa, int pb, int pc)
  {
    pair<int, int> ba{points[pa].first - points[pb].first, points[pa].second - points[pb].second};
    pair<int, int> cb{points[pb].first - points[pc].first, points[pb].second - points[pc].second};
    pair<int, int> ca{points[pa].first - points[pc].first, points[pa].second - points[pc].second};
    if (dot_product(ba, cb) == 0 && (abs(float(dot_product(ba, {1, 0})) / (mod(ba) * mod({1, 0}))) == 1 || abs(float(dot_product(ba, {0, 1})) / (mod(ba) * mod({0, 1}))) == 1) && (abs(float(dot_product(cb, {1, 0})) / (mod(cb) * mod({1, 0}))) == 1 || abs(float(dot_product(cb, {0, 1})) / (mod(cb) * mod({0, 1}))) == 1))
    {
      area = (abs(points[pa].first - points[pb].first) + abs(points[pa].second - points[pb].second)) * (abs(points[pb].first - points[pc].first) + abs(points[pb].second - points[pc].second));
      return true;
    }
    if (dot_product(cb, ca) == 0 && (abs(float(dot_product(cb, {1, 0})) / (mod(cb) * mod({1, 0}))) == 1 || abs(float(dot_product(cb, {0, 1})) / (mod(cb) * mod({0, 1}))) == 1) && (abs(float(dot_product(ca, {1, 0})) / (mod(ca) * mod({1, 0}))) == 1 || abs(float(dot_product(ca, {0, 1})) / (mod(ca) * mod({0, 1}))) == 1))
    {
      area = (abs(points[pb].first - points[pc].first) + abs(points[pb].second - points[pc].second)) * (abs(points[pa].first - points[pc].first) + abs(points[pa].second - points[pc].second));
      return true;
    }
    if (dot_product(ba, ca) == 0 && (abs(float(dot_product(ba, {1, 0})) / (mod(ba) * mod({1, 0}))) == 1 || abs(float(dot_product(ba, {0, 1})) / (mod(ba) * mod({0, 1}))) == 1) && (abs(float(dot_product(ca, {1, 0})) / (mod(ca) * mod({1, 0}))) == 1 || abs(float(dot_product(ca, {0, 1})) / (mod(ca) * mod({0, 1}))) == 1))
    {
      area = (abs(points[pa].first - points[pb].first) + abs(points[pa].second - points[pb].second)) * (abs(points[pa].first - points[pc].first) + abs(points[pa].second - points[pc].second));
      return true;
    }
    return false;
  };
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        if (is_right_angled(i, j, k))
        {
          ans = max({ans, area});
        }
      }
    }
  }
  cout << ans;
}

int main()
{
  auto start = high_resolution_clock::now();
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef OJ_FileIO
  setIO("triangles");
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