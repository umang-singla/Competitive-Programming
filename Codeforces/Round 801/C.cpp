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
    int n,m;
    cin>>n>>m;
    int a[n][m];
    FOR(i,0,n){
        FOR(j,0,m) cin>>a[i][j];
    }

    if((n+m-1)%2==1) cout<<"NO"<<endl;
    else{
        FOR(i,0,n){
            FOR(j,0,m) if(a[i][j]==-1) a[i][j] = 0;
        }

        int dp1[n][m],dp2[n][m];
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        dp1[0][0] = a[0][0];
        dp2[0][0] = a[0][0];

        FOR(i,1,m) dp1[0][i] = a[0][i] + dp1[0][i-1];
        FOR(i,1,n) dp1[i][0] = a[i][0] + dp1[i-1][0];

        FOR(i,1,m) dp2[0][i] = a[0][i] + dp2[0][i-1];
        FOR(i,1,n) dp2[i][0] = a[i][0] + dp2[i-1][0];

        FOR(i,1,n){
            FOR(j,1,m){
                dp1[i][j] = min(dp1[i-1][j]+a[i][j],dp1[i][j-1]+a[i][j]);
            }
        } 
        FOR(i,1,n){
            FOR(j,1,m){
                dp2[i][j] = max(dp2[i-1][j]+a[i][j],dp2[i][j-1]+a[i][j]);
            }
        } 

        // FOR(i,0,n){
        //     FOR(j,0,m) cout<<dp2[i][j]<<" ";
        //     cout<<endl;
        // }

        if(dp1[n-1][m-1] <= (n+m-1)/2 && dp2[n-1][m-1] >= (n+m-1)/2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}