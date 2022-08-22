#include <bits/stdc++.h>
#define modulo 1000000007
//#define int long long int

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    int c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    // ysort(c, c + n);

    int dp[x + 1];
    // memset(dp,0,sizeof(dp));

    for (int i = 0; i <= x; i++)
    {
        dp[i] = 0;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     // dp[i] = 0;
    //     if (c[i] <= x)
    //         dp[c[i]]++;
    // }

    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        //dp[c[i]] = 1;
        for (int j = 0; j <= x - c[i]; j++)
        {
            dp[j + c[i]] = (dp[j + c[i]] + dp[j]) % modulo;
        }
    }

    cout << dp[x] << endl;

    return 0;
}