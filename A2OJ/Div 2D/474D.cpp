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

#define mod 1000000007

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,k;cin >> t>>k;

    int dp[100000+1];

    dp[0] = 1;

    for(int i=1;i<=100000;i++){
        if(i>=k){
            dp[i] = (dp[i-1] + dp[i-k])%mod;
        }else{
            dp[i] = dp[i-1];
        }
    }

    int prefix[100000+1];
    prefix[0] = 0;

    for(int i=1;i<=100000;i++){
        prefix[i] = (prefix[i-1] + dp[i])%mod;
    }
    
    while (t--){

        int a,b;
        cin >> a >> b;

        cout<<(prefix[b] - prefix[a-1] + mod)%mod<<endl;

    }
}