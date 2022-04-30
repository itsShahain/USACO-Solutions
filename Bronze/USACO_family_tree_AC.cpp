#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;
using ll = long long;
// #define RUNTIME ;
#define OJ_FileIO ;

void setIO(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int N, tr_a, tr_b;
string a, b;
vector<int> adjList_uni[101];
vector<int> adjList_bi[101];
bool visited[101]{false};
set<string> cows;
vector<pair<string, string>> cow_pairs;
map<string, int> transpose;
map<int, string> reverse_transpose;
vector<pair<int, int>> tree_traversal_arr;
int search_depth;
int target_node;
bool found;
int root;

void range_min_query(int node1, int node2)
{
	int index1 = INT32_MAX, index2 = INT32_MAX;
	for (int i = 0; i < (int)tree_traversal_arr.size(); i++)
	{
		if (tree_traversal_arr[i].first == node1)
		{
			index1 = i;
			break;
		}
	}
	for (int i = 0; i < (int)tree_traversal_arr.size(); i++)
	{
		if (tree_traversal_arr[i].first == node2)
		{
			index2 = i;
			break;
		}
	}
	if (index1 == INT32_MAX || index2 == INT32_MAX)
	{
		cout << "NOT RELATED";
		return;
	}

	if (index1 > index2)
	{
		swap(a, b);
		swap(index1, index2);
	}
	int lowest = tree_traversal_arr[index1 + 1].second;
	// int LCA = tree_traversal_arr[index1 + 1].first;
	for (int i = index1 + 2; i < index2; i++)
	{
		if (tree_traversal_arr[i].second < lowest)
		{
			lowest = tree_traversal_arr[i].second;
			// LCA = tree_traversal_arr[i].first;
		}
	}
	// cout << LCA << "\n";
	int DISTA = tree_traversal_arr[index1].second - lowest;
	int DISTB = tree_traversal_arr[index2].second - lowest;
	// cout << DISTA << " " << DISTB;
	if (DISTA == 1 && DISTB == 1)
	{
		cout << "SIBLINGS";
		return;
	}
	if (DISTA > 1 && DISTB > 1)
	{
		cout << "COUSINS";
		return;
	}
	if (DISTA > DISTB)
	{
		int numberofgs = DISTA - 2;
		cout << b << " is the ";
		for (int i = 0; i < numberofgs; i++)
		{
			cout << "great-";
		}
		cout << "aunt of " << a;
		return;
	}
	if (DISTA < DISTB)
	{
		int numberofgs = DISTB - 2;
		cout << a << " is the ";
		for (int i = 0; i < numberofgs; i++)
		{
			cout << "great-";
		}
		cout << "aunt of " << b;
		return;
	}
}

void dfs_DA(int node, int depth)
{
	if (visited[node])
		return;
	visited[node] = true;
	if (node == target_node)
	{
		found = true;
		search_depth = depth;
	}
	for (auto &data : adjList_uni[node])
	{
		dfs_DA(data, depth + 1);
	}
}

void find_root(int node)
{
	if (visited[node])
		return;
	visited[node] = true;
	root = node;
	for (auto &data : adjList_uni[node])
	{
		find_root(data);
	}
}
// Find lowset common ancestor
void find_LCA(int node, int depth)
{
	if (visited[node])
		return;
	visited[node] = true;
	// if (node == 99)
	// {
	// 	int a;
	// 	cout << "";
	// }

	for (auto &data : adjList_bi[node])
	{
		// if (data == 100)
		// {
		// 	cout << "Shahain is a loser";
		// }

		tree_traversal_arr.push_back({node, depth});
		find_LCA(data, depth + 1);
	}
}

void solve()
{
	cin >> N;
	cin >> a >> b;
	for (int i = 0; i < N; i++)
	{
		string cow1, cow2;
		cin >> cow1 >> cow2;
		cow_pairs.push_back({cow1, cow2});
		cows.insert(cow1);
		cows.insert(cow2);
	}
	int count = 0;
	for (auto &data : cows)
	{
		transpose.insert({data, count});
		reverse_transpose.insert({count, data});
		count++;
	}
	for (auto data : cow_pairs)
	{
		adjList_uni[transpose[data.second]].push_back(transpose[data.first]);
		adjList_bi[transpose[data.first]].push_back(transpose[data.second]);
		adjList_bi[transpose[data.second]].push_back(transpose[data.first]);
	}

	tr_a = transpose[a];
	tr_b = transpose[b];

	target_node = transpose[b];
	found = false;
	memset(visited, false, 101);
	dfs_DA(transpose[a], 0);
	if (found)
	{
		string relationship;
		if (search_depth == 1)
		{
			relationship = "mother";
			cout << b << " is the " << relationship << " of " << a;
			return;
		}
		else
		{
			for (int i = 0; i < search_depth - 2; i++)
			{
				relationship += "great-";
			}
			relationship += "grand-mother";
			cout << b << " is the " << relationship << " of " << a;
			return;
		}
	}

	// check for direct ancestry
	// now check if a is a direct ancestor of b
	target_node = transpose[a];
	found = false;
	memset(visited, false, 101);
	dfs_DA(transpose[b], 0);
	if (found)
	{
		string relationship;
		if (search_depth == 1)
		{
			relationship = "mother";
			cout << a << " is the " << relationship << " of " << b;
			return;
		}
		else
		{
			for (int i = 0; i < search_depth - 2; i++)
			{
				relationship += "great-";
			}
			relationship += "grand-mother";
			cout << a << " is the " << relationship << " of " << b;
			return;
		}
	}
	memset(visited, false, 101);
	find_root(tr_b);
	memset(visited, false, 101);
	find_LCA(root, 1);

	// cout << "node  : ";
	// for (auto &data : tree_traversal_arr)
	// {
	// 	cout << data.first << " ";
	// }
	// cout << "\n"
	// 		 << "depth : ";
	// for (auto &data : tree_traversal_arr)
	// {
	// 	cout << data.second << " ";
	// }
	// cout << "\n\n";
	range_min_query(tr_a, tr_b);
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