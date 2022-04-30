#include <bits/stdc++.h>
using namespace std;
void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
  setIO("circlecross");
  string s;
  cin >> s;
  bool checkedLetters[26]{};
  bool allPairs[26][26]{};
  for (int i = 0; i < (int)s.size(); i++)
  {
    int startLetter = int(s[i]) - 65;
    if (checkedLetters[startLetter])
    {
      continue;
    }
    checkedLetters[int(s[i]) - 65] = true;

    for (int j = i + 1; j < (int)s.size(); j++)
    {
      int currentLetter = int(s[j]) - 65;
      if (currentLetter == startLetter)
      {
        break;
      }
      allPairs[startLetter][currentLetter] = true;
    }
  }
  int ans = 0;
  for (int i = 0; i < 26; i++)
  {
    for (int j = i + 1; j < 26; j++)
    {
      if (allPairs[i][j] && allPairs[j][i])
      {
        ans++;
      }
    }
  }
  cout << ans;
}