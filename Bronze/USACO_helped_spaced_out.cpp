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
	int grid[1000][1000]{0};
	int N;
	cin >> N;
	int vert = 0, hori = 0;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			cin >> grid[row][col];
		}
	}
	for (int row = 0; row < N; row++)
	{
		int evenSum = 0, oddSum = 0;
		for (int col = 0; col < N; col++)
		{
			if (col % 2 == 0)
			{
				evenSum += grid[row][col];
			}
			else
			{
				oddSum += grid[row][col];
			}
		}
		vert += max(evenSum, oddSum);
	}
	for (int col = 0; col < N; col++)
	{
		int evenSum = 0, oddSum = 0;
		for (int row = 0; row < N; row++)
		{
			if (row % 2 == 0)
			{
				evenSum += grid[row][col];
			}
			else
			{
				oddSum += grid[row][col];
			}
		}
		hori += max(oddSum, evenSum);
	}
	cout << max(vert, hori);
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
	auto duration = duration_cast<nanoseconds>(stop - start);
#ifdef RUNTIME
	cout << "\n"
			 << "Run time : " << duration.count() << " nanoseconds";
#endif
	return 0;
}