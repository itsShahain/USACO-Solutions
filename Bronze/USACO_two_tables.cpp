#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t, W, H, x1, y1, x2, y2, w, h;
  cin >> t;
  while (t--)
  {
    cin >> W >> H;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> w >> h;
    long long INF = 1e9;
    long long ans = INF;
    // Try adding it onto the left or right of the main table

    if ((w + (x2 - x1)) <= W)
    {
      ans = min(ans, max(w - x1, (long long)0));
      ans = min(ans, max(x2 - (W - w), (long long)0));
    }
    if ((h + (y2 - y1)) <= H)
    {
      ans = min(ans, max(h - y1, (long long)0));
      ans = min(ans, max(y2 - (H - h), (long long)0));
    }

    if (ans == INF)
    {
      cout << -1 << "\n";
    }
    else
    {
      ans = (float)ans;
      cout << ans << "\n";
    }
  }
}
// 1 3
// 0 0 1 1
// 1 1