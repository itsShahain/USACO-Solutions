#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define RUNTIME ;
#define OJ_FileIO ;

void setIO(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve()
{
	int N;
	cin >> N;
	map<int, int> transpose;
	vector<int> adjList[N];
	vector<int> cows(N);
	vector<int> cowsPassingToThisDood(N);
	for (auto &data : cows)
	{
		cin >> data;
		data--;
	}
	sort(all(cows));
	for (int i = 0; i < N; i++)
	{
		transpose.insert({cows[i], i});
	}
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			adjList[transpose[cows[i]]].push_back(transpose[cows[i + 1]]);
			cowsPassingToThisDood[transpose[cows[i + 1]]]++;
			continue;
		}

		if (i == (N - 1))
		{
			adjList[transpose[cows[i]]].push_back(transpose[cows[i - 1]]);
			cowsPassingToThisDood[transpose[cows[i - 1]]]++;
			continue;
		}

		if ((cows[i + 1] - cows[i]) < (cows[i] - cows[i - 1]))
		{
			adjList[transpose[cows[i]]].push_back(transpose[cows[i + 1]]);
			cowsPassingToThisDood[transpose[cows[i + 1]]]++;
		}
		else
		{
			adjList[transpose[cows[i]]].push_back(transpose[cows[i - 1]]);
			cowsPassingToThisDood[transpose[cows[i - 1]]]++;
		}
	}
	int ball = 0;
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			if (cowsPassingToThisDood[i] == 0)
			{
				ball++;
			}
			else if (adjList[i + 1][0] == i && adjList[i][0] == i + 1 && cowsPassingToThisDood[i] == 1 && cowsPassingToThisDood[i + 1] == 1)
			{
				ball++;
			}
			continue;
		}
		if (i == N - 1)
		{
			if (cowsPassingToThisDood[i] == 0)
			{
				ball++;
			}
			continue;
		}
		if (cowsPassingToThisDood[i] == 0)
		{
			ball++;
		}
		else if (adjList[i + 1][0] == i && adjList[i][0] == i + 1 && cowsPassingToThisDood[i] == 1 && cowsPassingToThisDood[i + 1] == 1)
		{
			ball++;
		}
	}

	cout << ball;
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