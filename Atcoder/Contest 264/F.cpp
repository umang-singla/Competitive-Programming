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
    int h,w;
    cin>>h>>w;
    int r[h],c[w];
    for(int i=0;i<h;i++) cin>>r[i];
    for(int i=0;i<w;i++) cin>>c[i];

    int a[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++) cin>>a[i][j];
    }

    // 0 -> none, 1 -> row, 2 -> column

    int dp[h][w][3];

    dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = 0;

    for(int j=1;j<w;j++){
        if(a[0][j]==a[0][j-1]){
            dp[0][j][0] = min(dp[0][j-1][0],dp[0][j-1][1]);
            dp[0][j][1] = dp[0][j-1][2] + r[0];
            dp[0][j][2] = dp[0][j-1][2] + c[j];
        }else{
            dp[0][j][0] = dp[0][j-1][1];
            dp[0][j][1] = min(dp[0][j-1][0],dp[0][j-1][2]) + r[0];
            dp[0][j][2] = dp[0][j-1][0] + c[j];
        }
    }

    for(int j=1;j<h;j++){
        if(a[j][0]==a[j-1][0]){
            dp[j][0][0] = min(dp[0][j-1][0],dp[0][j-1][2]);
            dp[j][0][1] = dp[j-1][0][1] + r[j];
            dp[0][j][2] = dp[j-1][0][1] + c[j];
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}