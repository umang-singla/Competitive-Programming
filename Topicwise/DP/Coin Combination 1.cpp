#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define int long long int

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    int c[n];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }

    int dp[x+1] = {0};

    dp[0] = 0;

    for(int i=1;i<=x;i++){
        int ans = 0;
        for(int j=0;j<n;j++){
            if(i-c[j]>0&&dp[i-c[j]]!=0) ans += dp[i-c[j]]%modulo;
            else if(i-c[j]==0) ans+= 1;
        }
        dp[i] = ans%modulo;
        //cout<<dp[i]<<" ";
    }

    cout<<dp[x]<<endl;

}