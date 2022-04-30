#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;
using ll = long long;
#define RUNTIME ;
#define OJ_FileIO ;

int N, a, b, ans = INT32_MAX;
vector<int> adjList[100];
vector<bool> visited(100, false);

void setIO(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void dfs(int node)
{
	if (visited[node])
		return;
	visited[node] = true;
	for (auto &degree : adjList[node])
	{
		dfs(degree);
	}
}

void solve()
{
	cin >> N;
	while (cin >> a >> b)
	{
		a--;
		b--;
		adjList[b].push_back(a);
	}
	for (int i = 0; i < N; i++)
	{
		visited.resize(N);
		for (int i = 0; i < N; i++)
		{
			visited[i] = false;
		}
		dfs(i);
		bool OK = true;
		for (auto status : visited)
		{
			OK &= status;
		}
		if (OK)
			ans = min(ans, i);
	}
	if (ans == INT32_MAX)
	{
		cout << -1;
	}
	else
	{

		cout << ++ans << '\n';
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
	auto duration = duration_cast<milliseconds>(stop - start);
#ifdef RUNTIME
	cout << "\n"
			 << "Run time : " << duration.count();
#endif
	return 0;
}