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
    int n,m;
    cin>>n>>m;

    int a[n];
    FOR(i,0,n) cin>>a[i];

    int k;
    cin>>k;

    int b[k];
    FOR(i,0,k) cin>>b[i];

    vector<pair<int,int>> c,d;

    int temp = a[0];
    while(temp%m == 0) temp/=m;

    c.pb({temp,a[0]/temp});

    FOR(i,1,n){
        int temp = a[i];
        while(temp%m == 0) temp/=m;
        if(c[c.size()-1].ff == temp) c[c.size()-1].ss += a[i]/temp;
        else c.pb({temp,a[i]/temp});
    }
    
    temp = b[0];
    while(temp%m == 0) temp/=m;

    d.pb({temp,b[0]/temp});

    FOR(i,1,k){
        int temp = b[i];
        while(temp%m == 0) temp/=m;
        if(d[d.size()-1].ff == temp) d[d.size()-1].ss += b[i]/temp;
        else d.pb({temp,b[i]/temp});
    }

    if(c.size()!=d.size()){
        // FOR(i,0,c.size()){
        //     cout<<c[i].first<<" "<<c[i].second<<endl;
        // }
        // cout<<endl;
        // FOR(i,0,d.size()) cout<<d[i].ff<<" "<<d[i].ss<<endl;
        cout<<"NO"<<endl;
    }else{
        bool equal = true;

        FOR(i,0,c.size()){
            if(c[i]!=d[i]) {
                equal = false;
                // cout<<c[i].first<<" "<<c[i].second<<" "<<d[i].ff<<" "<<d[i].ss<<endl;
            }
        }

        if(equal) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}