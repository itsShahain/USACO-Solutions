#include "bits/stdc++.h"

using namespace std;

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

bool pairs[8][8]{false};
int cow1, cow2;
vector<int> perm{0, 1, 2, 3, 4, 5, 6, 7};
set<int> cows_concerned;
vector<string> candidate_perm;
string winner = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
map<string, int> cow_num = {
    {"Bessie", 0},
    {"Buttercup", 1},
    {"Belinda", 2},
    {"Beatrice", 3},
    {"Bella", 4},
    {"Blue", 5},
    {"Betsy", 6},
    {"Sue", 7}

};
map<int, string> num_cow = {
    {0, "Bessie"},
    {1, "Buttercup"},
    {2, "Belinda"},
    {3, "Beatrice"},
    {4, "Bella"},
    {5, "Blue"},
    {6, "Betsy"},
    {7, "Sue"}

};
// int map_name(string);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  setIO("prob");
  int N;
  cin >> N;
  while (N--)
  {
    string s1, ig1, ig2, ig3, ig4, s2;
    cin >> s1 >> ig1 >> ig2 >> ig3 >> ig4 >> s2;
    cow1 = cow_num[s1];
    cow2 = cow_num[s2];
    cows_concerned.insert(cow1);
    cows_concerned.insert(cow2);
    pairs[cow1][cow2] = pairs[cow2][cow1] = true;
  }
  // iota(perm.begin(), perm.end(), 0);
  do
  {
    // for (auto data : perm)
    // {
    //     cout << num_cow[data] << " ";
    // };
    // cout << "\n";

    bool OK = true;
    bool test_grid[8][8]{false};
    for (int row = 0; row < 8; row++)
    {
      for (int col = 0; col < 8; col++)
      {
        test_grid[row][col] = pairs[row][col];
      }
    }

    for (int i = 0; i < 7; i++)
    {
      // if (cows_concerned.find(perm[i]) != cows_concerned.end() && cows_concerned.find(perm[i + 1]) != cows_concerned.end())
      // {
      test_grid[perm[i]][perm[i + 1]] = !test_grid[perm[i]][perm[i + 1]];
      test_grid[perm[i + 1]][perm[i]] = !test_grid[perm[i + 1]][perm[i]];
      // }
    }
    for (int row = 0; row < 8; row++)
    {
      for (int col = 0; col < 8; col++)
      {
        if (pairs[row][col])
        {
          if (test_grid[row][col])
          {
            OK = false;
            break;
          }
        }
      }
      if (!OK)
      {
        break;
      }
    }
    if (OK)
    {
      for (auto data : perm)
      {
        candidate_perm.push_back(num_cow[data]);
      };
      string temp;
      for (auto data : candidate_perm)
      {
        temp = temp + data + "\n";
      }
      winner = (temp < winner) ? temp : winner;
      candidate_perm.resize(0);
    }
  } while (next_permutation(perm.begin(), perm.end()));
  cout << winner;
  // string comeon = ("Belinda\nBessie\nBeatrice\nBella\nBlue\nBetsy\nButtercup\nSue\n" < "Beatrice\nBelinda\nBessie\nBella\nBlue\nBetsy\nButtercup\nSue\n") ? "Belinda\nBessie\nBeatrice\nBella\nBlue\nBetsy\nButtercup\nSue\n" : "Beatrice\nBelinda\nBessie\nBella\nBlue\nBetsy\nButtercup\nSue\n";
  // cout << comeon;
  return 0;
}
