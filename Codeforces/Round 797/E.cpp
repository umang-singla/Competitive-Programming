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
    int n,k;
    cin>>n>>k;
    int a[n];
    FOR(i,0,n) cin>>a[i];

    int mod[k]={0};
    FOR(i,0,n) mod[a[i]%k]++;
    int ans = 0;
    FOR(i,0,n) ans += a[i]/k;

    // FOR(i,0,k) cout<<mod[i]<<" ";

    int i=1,j=k-1;
    while(i<j){
        if(mod[i]>0&&mod[j]>0){
            if(i+j>=k){
                int temp = min(mod[i],mod[j]);
                ans += temp;
                mod[i]-=temp;
                mod[j]-=temp;
            }else i++;
        }

        if(mod[i]==0) i++;
        if(mod[j]==0) j--;        
    }
    // cout<<i<<" ";
    if(i==j && 2*i >= k)ans += mod[i]/2;

    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}