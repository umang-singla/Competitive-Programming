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
    int m,n;
    cin>>m>>n;

    int t[n],z[n],y[n];

    FOR(i,0,n)cin>>t[i]>>z[i]>>y[i];

    int st=0,ed=INT_MAX;
    while (st<ed)
    {
        int mid = (st+ed)/2;

        int balloon=0;
        // cout<<mid<<" ";

        FOR(i,0,n){
            balloon += z[i]*(mid/(t[i]*z[i]+y[i])) + min(z[i],(mid%(t[i]*z[i]+y[i]))/t[i]);
        }

        // if(mid==1) cout<<balloon<<" ";

        if(balloon>=m) ed=mid;
        else st = mid+1;
    }

    int time = st;

    cout<<time<<endl;

    FOR(i,0,n){
        int balloon = min(m,z[i]*(time/(t[i]*z[i]+y[i])) + min(z[i],(time%(t[i]*z[i]+y[i]))/t[i]));
        cout<<balloon<<" ";
        m-=balloon;
    }
    cout<<endl;
    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}