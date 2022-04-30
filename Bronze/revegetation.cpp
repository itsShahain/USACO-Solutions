#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;
using ll = long long;
// #define RUNTIME ;
// Uncomment to measure running time of the algorithm in milliseconds.
#define OJ_FileIO ;

int N, M, a, b;
int seed_barn;
vector<int> adjList[100];
bool visited[100]{false};
set<int> possible_seeds;
vector<int> barn(100, 0);

void setIO(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void dfs(int node, int depth)
{
	if (depth == 2)
		return;
	if (visited[node])
		return;
	visited[node] = true;
	possible_seeds.insert(barn[node]);
	for (auto vertex : adjList[node])
	{
		dfs(vertex, depth + 1);
	}
}

void solve()
{

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		a--;
		b--;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	for (int i = 0; i < N; i++)
	{
		memset(visited, false, 100);
		seed_barn = 0;
		dfs(i, 0);
		for (int i = 0; i <= 4; i++)
		{
			if (!possible_seeds.count(i))
			{
				seed_barn = i;
				break;
			}
		}

		barn[i] = seed_barn;
		possible_seeds.clear();
		cout << seed_barn;
	}
}

int main()
{
	auto start = high_resolution_clock::now();
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef OJ_FileIO
	setIO("revegetate");
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