#include <bits/stdc++.h>
#define mod 1000000007
#define int long long int

using namespace std;

signed main()
{
    int n, k, d;
    cin >> n >> k >> d;

    int dp[n + 1][d + 1];
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<=d;i++)
        dp[0][i] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            for (int p = 1; p <= k; p++)
            {
                if(j>i) dp[i][j] = 0;
                else if (j - p > 0 && i - p >= 0)
                {
                    dp[i][j] = (dp[i - p][j] + dp[i][j]) % mod;
                }
                else if (j - p <= 0 && i - p >= 0)
                {
                    dp[i][j] = (dp[i - p][1] + dp[i][j]) % mod;
                }
            }
        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=d;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout << dp[n][d] << endl;

    return 0;
}