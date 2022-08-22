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

    int prefix[n+1];
    prefix[0]=1;
    for(int i=0;i<n;i++) prefix[i+1] = prefix[i]+a[i];

    vi v;
    FOR(i,0,n){
        if(a[i]>0)v.pb(i);
    }


    bool poss=true;

    int st = v[0],ed=v[0];
    for(int i=1;i<(int)v.size();i++){
        if(v[i]-v[i-1]==1){
            poss=false;
        }else{
            int m = v[i];
            for(int j=v[i-1];j<=v[i];j++){
                m = max(m,a[j]);
            }
            if(m<(prefix[v[i]+1]-prefix[v[i-1]])) poss = false;

        }
    }

    if(poss) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}