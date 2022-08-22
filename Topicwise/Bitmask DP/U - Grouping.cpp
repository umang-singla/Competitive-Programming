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
int score[10000000];
int dp[100000000];


int solve(int mask){
    if(mask == 0) return 0;

    if(dp[mask]!=-1) return dp[mask];

    int ans = 0;

    for(int submask = mask ;submask;submask = (submask-1)&mask){
        ans = max(ans,score[submask]+solve(mask^submask));
    }

    dp[mask] = ans;

    return ans;

}


void testcase()
{
    int n;
    cin>>n;
    int a[n][n];
    FOR(i,0,n){
        FOR(j,0,n) cin>>a[i][j];
    }
    memset(score,0,sizeof(score));
    memset(dp,-1,sizeof(dp));

    for(int mask=1;mask<(1<<n);mask++){
        int temp=0;
        for(int i=0;i<n;i++){
            if(mask&(1<<i)) {
                temp = i;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                score[mask] += a[temp][i]; 
            }
        }

        score[mask] += score[mask^(1<<temp)];
    }

    // cout<<'a';

    cout<<solve((1<<n)-1)<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}