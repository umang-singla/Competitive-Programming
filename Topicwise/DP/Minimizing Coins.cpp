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

    int dp[x+1] = {-1};

    dp[0] = 0;

    for(int i=1;i<=x;i++){
        int ans = INT_MAX;
        for(int j=0;j<n;j++){
            if(i-c[j]>=0) ans = min(ans,1+dp[i-c[j]]);
        }
        dp[i] = ans;
    }

    if(dp[x] == INT_MAX) cout<<-1<<endl;
    else cout<<dp[x]<<endl;

}