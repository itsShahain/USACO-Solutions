#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout);
  int N;
  int Letters[26]{};
  scanf("%d", &N);
  while (N--)
  {
    char find[2]{};

    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < 26; i++)
    {
      sprintf(find, "%c", i + 97);
      char foundChar = *find;
      int s1occ = count(s1.begin(), s1.end(), foundChar);
      int s2occ = count(s2.begin(), s2.end(), foundChar);
      Letters[i] += max(s1occ, s2occ);
    }
  }
  for (auto data : Letters)
  {
    cout << data << "\n";
  }
}