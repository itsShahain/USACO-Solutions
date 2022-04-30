#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;
using ll = long long;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nl '\n'
// #define RUNTIME
// #define OJ_FileIO

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

void solve()
{
  int t;
  cin >> t;
  while (t--)
  {
    vector<int> A(4);
    vector<int> B(4);
    for (auto &data : A)
      cin >> data;
    for (auto &data : B)
      cin >> data;
    int XgY = 0;
    int YgX = 0;
    bool OK;
    auto compare = [&](const vector<int> &X, const vector<int> &Y)
    {
      XgY = 0;
      YgX = 0;
      for (int i = 0; i < 4; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          if (X[i] > Y[j])
            XgY++;
          else if (X[i] != Y[j])
            YgX++;
        }
      }
    };
    auto find_C_alpha = [&]()
    { vector<int> C(4);
      for (int i = 1; i <= 10; i++)
      {
        C[0] = i;
        for (int j = 1; j <= 10; j++)
        {
          C[1] = j;
          for (int k = 1; k <= 10; k++)
          {
            C[2] = k;

            for (int l = 1; l <= 10; l++)
            {
              C[3] = l;
              
              compare(B, C);
              if (XgY < YgX || XgY == YgX)
                continue;
              compare(A, C);
              if (XgY < YgX && XgY != YgX){
                OK = true;
                cout << "yes" <<nl;
                // for(auto&data:C)cout << data << " ";
                return;
              }
            }
          }
        }
      } };
    auto find_C_beta = [&]()
    { vector<int> C(4);
      for (int i = 1; i <= 10; i++)
      {
        C[0] = i;
        for (int j = 1; j <= 10; j++)
        {
          C[1] = j;
          for (int k = 1; k <= 10; k++)
          {
            C[2] = k;

            for (int l = 1; l <= 10; l++)
            {
              C[3] = l;
              compare(C, B);
              if (XgY < YgX || XgY == YgX)
                continue;
              compare(C, A);
              if (XgY < YgX && XgY != YgX){
                OK = true;
                cout << "yes" <<nl;
                // for(auto&data:C)cout << data << " ";
                return;
              }
            }
          }
        }
      } };
    compare(A, B);
    if (XgY > YgX)
    {
      // Then A is more likely to win than B
      // A>B B>C C>A
      OK = false;
      find_C_alpha();
      if (!OK)
        cout << "no" << nl;
    }
    else
    {
      // Then B is more likely to win than A
      //  B>A C>B A>C
      OK = false;
      find_C_beta();
      if (!OK)
        cout << "no" << nl;
    }
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