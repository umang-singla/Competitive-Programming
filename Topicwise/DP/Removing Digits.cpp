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
    
    int dp[n+1];
    dp[0] = 1;

    for(int i=1;i<=n;i++){
        int sum = 0;
        for(int j=1;j<=6;j++){
            if(i>=j) sum += dp[i-j]%modulo;
            sum %= modulo;
        }
        dp[i] = sum%modulo;
    }

    cout<<dp[n]%modulo<<endl;

}