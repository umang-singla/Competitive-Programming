#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<<vi>>
#define vii vector<pii>
#define vll vector<pll>
#define FOR(i, l, r) for (int i = l; i < r; ++i)
#define FORr(i, l, r) for (int i = l; i >= r; --i)

#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())

#define int long long int

#define mod 100000000

using namespace std;

void testcase()
{
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    // testcase();
    int n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;

    int dp[n1+1][n2+1][k1+1][k2+1];

    memset(dp,0,sizeof(dp));

    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            dp[i][j][0][0] = 0;
        }
    }

    for(int i=0;i<=k1;i++){
        for(int j=0;j<=k2;j++){
            dp[0][0][i][j] = 1;
        }
    }

    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            for(int p=0;p<k1;p++){
                if(i>0&&p>0)dp[i][j][p][k2] += dp[i-1][j][p-1][k2];
                dp[i][j][p][k2] %= mod;
                if(j>0) dp[i][j][p][k2] += dp[i][j-1][k1][k2-1];
                dp[i][j][p][k2] %= mod;
            }
            for(int p=0;p<k2;p++){
                if(i>0)dp[i][j][k1][p] += dp[i-1][j][k1-1][k2];
                dp[i][j][k1][p]%=mod;
                if(j>0&&p>0) dp[i][j][k1][p] += dp[i][j-1][k1][p-1];
                dp[i][j][k1][p]%=mod;
            }
            if(i>0)dp[i][j][k1][k2] += dp[i-1][j][k1-1][k2];
            dp[i][j][k1][k2]%=mod;
            if(j>0) dp[i][j][k1][k2] += dp[i][j-1][k1][k2-1];
            dp[i][j][k1][k2]%=mod;
        }
    }

    // for(int i=0;i<=n1;i++){
    //     for(int j=0;j<=n2;j++){
    //         cout<<i<<" "<<j<<endl;
    //         for(int p=0;p<=k1;p++){
    //             for(int q=0;q<=k2;q++){
    //                 cout<<dp[i][j][p][q]<<" ";
    //             }
    //             cout<<endl;
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }

    cout<<dp[n1][n2][k1][k2]<<endl;

}