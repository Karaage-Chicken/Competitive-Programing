#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    string X, Y;
    cin >> q;
    vector<vector<int>> dp;
    for (int i = 0; i < q; i++)
    {
        cin >> X >> Y;
        dp.assign(X.size() + 1, vector<int>(Y.size() + 1, 0));

        for (int x = 0; x < X.size(); x++)
        {
            for (int y = 0; y < Y.size(); y++)
            {
                if (X[x] == Y[y])
                {
                    dp[x + 1][y + 1] = dp[x][y] + 1;
                }
                else
                {
                    dp[x + 1][y + 1] = max(dp[x][y + 1], dp[x + 1][y]);
                }
            }
        }
        cout << dp[X.size()][Y.size()] << endl;
    }
    system("pause");
    return 0;
}