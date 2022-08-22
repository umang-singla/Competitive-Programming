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
#define vvi vector< <vi> >
#define vii vector<pii>
#define vll vector<pll>
#define FOR(i, l, r) for (int i = l; i < r; ++i)
#define FORr(i, l, r) for (int i = l; i >= r; --i)

#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof ((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c, x)((c).find(x) != (c).end())
#define cpresent(c, x)(find(all(c), x) != (c).end())

#define int long long int

using namespace std;

void testcase(int c){

    int n,p;
    cin>>n>>p;

    vector <vector<int>> x(n,vector<int>(p));
    FOR(i,0,n){
        FOR(j,0,p){
            cin>>x[i][j];
        }
        sort(all(x[i]));
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<p;j++){
    //         cout<<x[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<'a';

    int dp[n][2];

    dp[0][0] = x[0][p-1]*2 - x[0][0];
    dp[0][1] = x[0][p-1];

    // cout<<dp[0][0]<<" "<<dp[0][1]<<endl;

    for(int i=1;i<n;i++){
        dp[i][0] = min(dp[i-1][0] + abs(x[i][p-1]-x[i-1][0]) + abs(x[i][p-1] - x[i][0]),dp[i-1][1] + abs(x[i][p-1] - x[i-1][p-1]) + abs(x[i][p-1] - x[i][0]));
        dp[i][1] = min(dp[i-1][0] + abs(x[i-1][0] - x[i][0]) + abs(x[i][p-1] - x[i][0]),dp[i-1][1] + abs(x[i-1][p-1] - x[i][0]) + abs(x[i][p-1] - x[i][0]));

        // cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }

    cout<<"Case #"<<c+1<<": "<<min(dp[n-1][0],dp[n-1][1])<<endl;




}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        testcase(i);
    }
}