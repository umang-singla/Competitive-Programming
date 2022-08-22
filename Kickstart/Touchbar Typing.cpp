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

void testcase(int c)
{
    int n;
    cin>>n;
    int s[n];
    FOR(i,0,n) cin>>s[i];
    int m;
    cin>>m;
    int k[m];
    FOR(i,0,m) cin>>k[i];

    map <int , set<int>> loc;
    FOR(i,0,m) loc[k[i]].insert(i);

    int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j] = INT_MAX;
        }
    }

    for(int i=0;i<m;i++){
        if(k[i] == s[n-1]) {
            dp[n-1][i] = 0;
            // cout<<dp[n-1][]
        }
        // else cout<<'a';
    }

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
            if(s[i] == k[j]){
                auto it = loc[s[i+1]].upper_bound(j);
                // cout<<j<<" "<<*it<<endl;
                if(it != loc[s[i+1]].end()){
                    dp[i][j] = min(dp[i][j],*it - j + dp[i+1][*it]);
                }
                if(it != loc[s[i+1]].begin()){
                    it--;
                    // cout<<*it<<endl;
                    dp[i][j] = min(dp[i][j],j - *it + dp[i+1][*it]);
                }
            }
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }

    int ans = INT_MAX;
    for(int i=0;i<m;i++) ans = min(ans,dp[0][i]);

    cout<<"Case #"<<c<<": "<<ans<<endl;


}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;
    for(int i=0;i<t;i++) testcase(i+1);
}