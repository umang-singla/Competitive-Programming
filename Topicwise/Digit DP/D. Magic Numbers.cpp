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

int mod = 1e9 + 7;

int m,d,len;
string a,b;

int dp[2002][2][2][2005];

int rec(int idx,int lo,int hi,int rem){

    if(idx==len){
        if(rem==0) return 1;
        else return 0;
    }

    if(dp[idx][lo][hi][rem]==-1){
        int loLim=0,hiLim=9;

        if(lo==1) loLim = a[idx]-'0';
        if(hi==1) hiLim = b[idx]-'0'; 
        int ans = 0;

        // cout<<loLim<<" "<<hiLim<<endl;

        for(int i=loLim;i<=hiLim;i++){

            int nhi=hi,nlo=lo;

            if(i!=b[idx]-'0') nhi = 0;
            if(i!=a[idx]-'0') nlo = 0;

            if((idx+1)%2==1){
                if(i!=d) ans = (ans+rec(idx+1,nlo,nhi,(rem*10+i)%m))%mod;
            }else{
                if(i==d) ans = (ans+rec(idx+1,nlo,nhi,(rem*10+i)%m))%mod;
            }

        }

        dp[idx][lo][hi][rem] = ans;
    }

    return dp[idx][lo][hi][rem];


}

void testcase()
{
    cin>>m>>d;
    cin>>a>>b;
    len=b.length();

    int extra = b.length()-a.length();
    string temp = "";
    memset(dp,-1,sizeof(dp));
    while(extra--) temp+='0'; a = temp + a;

    int ans = 0;
    ans = rec(0,1,1,0);

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