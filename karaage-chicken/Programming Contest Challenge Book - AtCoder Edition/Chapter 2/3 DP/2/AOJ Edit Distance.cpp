#include <bits/stdc++.h>

using namespace std;

int main()
{
    int INF = 1 << 10;
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> dp;
    dp.assign(s1.size() + 1, vector<int>(s2.size() + 1, INF));
    for (int i = 1; i <= s2.size(); i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= s1.size(); i++)
    {
        dp[i][0] = i;
    }

    dp[0][0] = 0;

    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
            }
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
    system("pause");
    return 0;
}