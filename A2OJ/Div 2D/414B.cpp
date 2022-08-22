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

#define mod 1000000007

void testcase()
{
    int n,k;
    cin>>n>>k;

    int dp[k][n+1];

    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++) dp[0][i]=1;

    for(int i=1;i<k;i++){
        for(int j=1;j<=n;j++){
            for(int p=j;p<=n;p+=j){
                dp[i][p] = (dp[i][p] + dp[i-1][j])%mod;
            }
        }
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = (ans + dp[k-1][i])%mod;
    }

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