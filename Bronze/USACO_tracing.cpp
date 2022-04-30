#include "bits/stdc++.h"

using namespace std;

int N, T;
bool cow_ends_infected[101];
int cowX[251]{}, cowY[251]{};

void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

bool test_validity(int patient_zero, int K)
{
    bool infected[101]{false};
    int num_handshakes[101]{0};
    int x, y;
    infected[patient_zero] = true;
    for (int i = 1; i <= 250; ++i)
    {
        x = cowX[i];
        y = cowY[i];
        if (x > 0)
        {
            if (infected[x])
                num_handshakes[x]++;
            if (infected[y])
                num_handshakes[y]++;
            if (infected[x] && num_handshakes[x] <= K)
                infected[y] = true;
            if (infected[y] && num_handshakes[y] <= K)
                infected[x] = true;
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        if (cow_ends_infected[i] != infected[i])
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    setIO("tracing");
    string S;
    cin >> N >> T;
    cin >> S;
    for (int i = 1; i <= N; ++i)
    {
        cow_ends_infected[i] = S[i - 1] == '1';
    }
    for (int i = 0; i < T; ++i)
    {
        int t, x, y;
        cin >> t >> x >> y;
        cowX[t] = x;
        cowY[t] = y;
    }
    set<int> patient_zero;
    vector<int> possible_Ks(0);
    for (int i = 1; i <= 100; ++i)
    {
        for (int j = 0; j <= 250; ++j)
        {
            if (test_validity(i, j))
            {
                patient_zero.insert(i);
                possible_Ks.push_back(j);
            }
        }
    }
    sort(possible_Ks.begin(), possible_Ks.end());
    cout << patient_zero.size();
    if (possible_Ks.front() >= T)
    {
        cout << " Infinity";
    }
    else
    {
        cout << " " << possible_Ks.front();
    }
    if (possible_Ks.back() >= T)
    {
        cout << " Infinity";
    }
    else
    {
        cout << " " << possible_Ks.back();
    }

    return 0;
}