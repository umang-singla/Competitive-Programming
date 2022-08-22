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
    int n;
    cin>>n;
    int a[n];
    FOR(i,0,n) cin>>a[i];

    map<int,vi> m;

    int ans=n,index=-1;
    m[a[0]].pb(0);
    for(int i=1;i<n;i++){
        if(m[a[i-1]].size()>1){
            index = max(index,m[a[i-1]][m[a[i-1]].size()-2]);
        }
        m[a[i]].pb(i);
        ans = min(ans,2*(n-i)+index+1);
    }

    if(m[a[n-1]].size()>1){
        index = max(index,m[a[n-1]][m[a[n-1]].size()-2]);
    }
    ans = min(ans,index+1);

    m.clear();

    index=n;
    m[a[n-1]].pb(n-1);
    for(int i=n-2;i>=0;i--){
        if(m[a[i+1]].size()>1){
            index = min(index,m[a[i+1]][m[a[i+1]].size()-2]);
        }
        m[a[i]].pb(i);
        ans = min(ans,2*(i+1)+(n-index));
    }
    if(m[a[0]].size()>1){
        index = min(index,m[a[0]][m[a[0]].size()-2]);
    }
    ans = min(ans,n-index);

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