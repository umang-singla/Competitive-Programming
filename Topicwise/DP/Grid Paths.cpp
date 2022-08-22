#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define int long long int

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    char grid[n][n+1];

    for(int i=0;i<n;i++){
        cin>>grid[i];
    }

    int dp[n][n];
    if(grid[0][0] == '.') dp[0][0] = 1;
    else dp[0][0] = 0;

    for(int i=1;i<n;i++){
        if(grid[0][i-1] == '.'&&grid[0][i] == '.') dp[0][i] = dp[0][i-1];
        else dp[0][i] = 0;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = 0;
            if(grid[i-1][j] == '.'&&grid[i][j] == '.') dp[i][j] += dp[i-1][j];
            if(grid[i][j-1] == '.'&&grid[i][j] == '.') dp[i][j] += dp[i][j-1];
            //if(grid[i-1][j] == '*'&&grid[i][j-1] == '*') dp[i][j] = 0;
            dp[i][j] %= modulo;
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" "; 
    //     }
    //     cout<<endl;
    // }

    cout<<dp[n-1][n-1]<<endl;

}