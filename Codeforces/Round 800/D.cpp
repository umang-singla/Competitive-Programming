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

    int l[n],r[n],p[n];
    FOR(i,1,n) cin>>p[i];
    p[0] = 1;
    FOR(i,0,n) cin>>l[i]>>r[i];

    int ans=0;

    int val[n]={0};

    vector<int> graph[n];
    graph[0].pb(0);
    FOR(i,1,n){
        graph[p[i]-1].pb(i);
    }

    stack<int> st;

    int visited[n]={0};
    visited[0]=1;

    // int ans = 0;
    
    FORr(i,n-1,0){
        if(val[i]<l[i]){
            ans ++;
            val[i] = r[i];
            val[p[i]-1] += r[i];
        }else{
            val[p[i]-1]+=min(val[i],r[i]);
        }
    }

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