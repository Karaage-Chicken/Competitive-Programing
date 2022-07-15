#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, W;
    cin >> N >> W;
    vector<int> v;
    vector<int> w;
    v.resize(N);
    w.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i] >> w[i];
    }

    vector<vector<int>> dp;
    dp.assign(N + 1, vector<int>(W + 1, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (j < w[i])
            {
                dp[i + 1][j] = dp[i][j];
            }
            else
            {
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[N][W] << endl;
    system("pause");
    return 0;
}