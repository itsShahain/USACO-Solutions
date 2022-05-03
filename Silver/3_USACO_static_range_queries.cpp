/*
 * author  : Shahain Manujith
 * created : 02 May 2022 16:05:06 +0530
 */
#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;
using ll = long long;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nl '\n'
#define RUNTIME
#define OJ_FileIO

#ifdef OJ_FileIO
void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
#endif

void solve()
{
  ll N, Q;
  cin >> N >> Q;
  ll l, r, v;
  vector<ll> intervals(400000);
  vector<ll> prefix(400000);
  vector<ll> indices;
  vector<pair<ll, pair<ll, ll>>> updates;
  vector<pair<ll, ll>> queries;
  for (ll i = 0; i < N; i++)
  {
    cin >> l >> r >> v;
    indices.push_back(l);
    indices.push_back(r);
    updates.push_back({l, {r, v}});
  }
  for (ll i = 0; i < Q; i++)
  {
    cin >> l >> r;
    indices.push_back(l);
    indices.push_back(r);
    queries.push_back({l, r});
  }
  sort(all(indices));
  indices.erase(unique(indices.begin(), indices.end()), indices.end());
  for (auto &data : updates)
  {
    ll lu = lower_bound(all(indices), data.first) - indices.begin();
    ll ru = lower_bound(all(indices), data.second.first) - indices.begin();
    lu++;
    ru++;
    intervals[lu] += data.second.second;
    intervals[ru] -= data.second.second;
  }
  for (ll i = 1; i < 400000; i++)
  {
    intervals[i] += intervals[i - 1];
  }
  for (ll i = 1; i < (ll)indices.size(); i++)
  {
    prefix[i] = prefix[i - 1] + intervals[i] * (indices[i] - indices[i - 1]);
  }

  for (auto &data : queries)
  {
    ll lq = lower_bound(all(indices), data.first) - indices.begin();
    ll rq = lower_bound(all(indices), data.second) - indices.begin();
    lq++;
    rq++;
    cout << prefix[rq - 1] - prefix[lq - 1] << nl;
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