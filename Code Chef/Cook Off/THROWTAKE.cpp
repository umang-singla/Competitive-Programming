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
    int c[n],v[n];
    FOR(i,0,n) cin>>c[i];
    FOR(i,0,n) cin>>v[i];

    vi odd;
    FOR(i,0,n){
        if(c[i]%2) odd.pb(v[i]);
    }

    n =  odd.size();
    if(n==0) cout<<0<<endl;
    else{
        int index1=0;
        int m=odd[0];
        FOR(i,0,n) {
            if(odd[i]>=m) {
                index1=i;
                m=odd[i];
            }
        }
        if(index1==n-1){
            cout<<odd[index1]<<endl;
        }else{
            int index2=index1+1;
            m=odd[index2];
            FOR(i,index2,n){
                if(m>=odd[i]){
                    index2=i;
                    m=odd[i];
                }
            }

            if(index1==n-1){
                cout<<max(odd[index2],odd[index1]-odd[index2])<<endl;
            }else{
                cout<<max(odd[n-1],min(odd[index1]+odd[n-1]-odd[index2],odd[index1]-odd[n-1]))<<endl;
            }
        }
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