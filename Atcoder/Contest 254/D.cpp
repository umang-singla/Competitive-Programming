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

    int a[n+1];
    FOR(i,0,n+1) a[i]=i;


    for(int i=1;i*i<=n;i++){
        for(int j=1;j*i*i<=n;j++){
            a[i*j*i] = min(a[i*j*i],j);
        }
    }

    // FOR(i,0,n+1) cout<<a[i]<<" ";

    map<int,int> m;
    FOR(i,1,n+1) m[a[i]]++;

    int ans=0;
    for(auto i:m){
        // cout<<i.first<<" ";
        ans += i.second*i.second;
    }

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