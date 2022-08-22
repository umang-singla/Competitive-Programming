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

using namespace std;

void testcase()
{
    int n;
    cin>>n;
    int a[n],b[n];
    FOR(i,0,n) cin>>a[i];
    FOR(i,0,n) cin>>b[i];

    int prefix[n+1];
    prefix[0]=0;
    FOR(i,0,n) prefix[i+1] = prefix[i] + a[i]*b[i];

    int dp[n][n];
    FOR(i,0,n) dp[i][i] = a[i]*b[i];

    int ans = prefix[n];
    FOR(i,0,n-1){
        int ans1 = prefix[n] - a[i]*b[i] - a[i+1]*b[i+1] + a[i]*b[i+1] + b[i]*a[i+1];
        dp[i][i+1] = a[i]*b[i+1] + b[i]*a[i+1];
        ans = max(ans,ans1);
    }

    FOR(i,2,n){
        FOR(j,0,n-i){
            int ans1 = dp[j+1][j+i-1];
            ans1+= a[j]*b[j+i] + a[j+i]*b[j];
            dp[j][j+i] = ans1;
            ans1 = prefix[n] - (prefix[j+i+1]-prefix[j]) + ans1;
            ans = max(ans,ans1);
        }
    }

    // FOR(i,0,n){
    //     FOR(j,i+1,n){
    //         if(i+1<=j-1){
    //             int ans1 = dp[i+1][j-1];
    //             ans1 += a[i]*b[j] + a[j]*b[i];
    //             ans1 = prefix[n] - (prefix[j+1]-prefix[i]) +ans1;
    //             dp[i][j] = ans1;
    //             ans = max(ans,ans1);
    //         }else{
    //             int ans1 = prefix[n] - a[i]*b[i] - a[j]*b[j] + a[i]*b[j] + a[j]*b[i];
    //             dp[i][j] = ans1;
    //             ans = max(ans,ans1);
    //         }
    //     }
    // }

    // FOR(i,0,n){
    //     FOR(j,0,n){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}