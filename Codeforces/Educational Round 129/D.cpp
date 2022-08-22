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

map <int,int> dp;
int n,x;

int solve(int x){

    int length = 0;
    int temp=x;
    // cout<<x<<endl;
    while(temp){
        length++;
        temp/=10;
    }
    if(length>=n){
        dp[x] = 0;
        return 0;
    }else{
        if(dp[x]>0){
            return dp[x];
        }else{
            int temp = x;
            int ans = INT_MAX;
            while (temp)
            {
                if(temp%10 > 1)ans = min(ans,1+solve((temp%10)*x));
                temp/=10;
            }

            dp[x] = ans;
            return ans;
        }
    }

}

void testcase()
{
    // int n,x;
    cin>>n>>x;


    int ans = solve(x);

    if(ans==INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;   
    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}