/*
 * author  : Shahain Manujith
 * created : 28 April 2022 18:42:51 +0530
 */
#include "bits/stdc++.h"

namespace std {
	
template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
}


using namespace std;
using namespace std::chrono;
using ll = long long;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nl '\n'
// #define RUNTIME
#define OJ_FileIO

#ifdef OJ_FileIO
void setIO(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
#endif

bool xcompare(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
};

void solve()
{
	int N, paint;
	set<int> vis_paints;
	cin >> N;
	vector<vector<pair<int, int>>> paints(N * N + 1);
	int grid[N + 1][N + 1]{0};
	int rect[N + 2][N + 2]{0};
	int prefix[N + 2][N + 2]{0};
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> paint;
			vis_paints.insert(paint);
			grid[y + 1][x + 1] = paint;
		}
	}

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			paints[grid[y][x]].push_back({y, x});
		}
	}
	for (int i = 1; i <= N * N; i++)
	{
		int tlx, tly, brx, bry;
		if (paints[i].size())
		{
			sort(all(paints[i]));
			tly = (*paints[i].begin()).first;
			bry = (*(paints[i].end() - 1)).first;
			sort(all(paints[i]), xcompare);
			tlx = (*paints[i].begin()).second;
			brx = (*(paints[i].end() - 1)).second;
			rect[tly][tlx]++;
			rect[tly][brx + 1]--;
			rect[bry + 1][tlx]--;
			rect[bry + 1][brx + 1]++;
		}
	}

	for (int y = 1; y <= N + 1; y++)
	{
		for (int x = 1; x <= N + 1; x++)
		{
			prefix[y][x] = rect[y][x] + prefix[y - 1][x] + prefix[y][x - 1] - prefix[y - 1][x - 1];
		}
	}
	set<int> invalid;
	for (int y = 1; y <= N + 1; y++)
	{
		for (int x = 1; x <= N + 1; x++)
		{
			if (prefix[y][x] > 1)
			{
				invalid.insert(grid[y][x]);
			}
		}
	}
	if (!invalid.size() && vis_paints.size() == 2)
		cout << N * N - 1 << nl;
	else
		cout << N * N - invalid.size() << nl;
}

int main()
{
	auto start = high_resolution_clock::now();
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef OJ_FileIO
	setIO("art");
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

