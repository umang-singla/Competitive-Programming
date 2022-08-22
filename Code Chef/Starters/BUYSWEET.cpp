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
#define vvi vector< <vi> >
#define vii vector<pii>
#define vll vector<pll>
#define FOR(i, l, r) for (int i = l; i < r; ++i)
#define FORr(i, l, r) for (int i = l; i >= r; --i)

#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof ((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c, x)((c).find(x) != (c).end())
#define cpresent(c, x)(find(all(c), x) != (c).end())

using namespace std;

bool comparator(const pii &a,const pii &b){
    return a.ff - a.second < b.ff - b.second;
}

void testcase(){

    int n,r;
    cin>>n>>r;

    pii p[n];

    FOR(i,0,n){
        cin>>p[i].ff;
    }

    FOR(i,0,n){
        cin>>p[i].ss;
    }

    sort(p,p+n,comparator);

    int ans = 0;

    for(int i=0;i<n;i++){
        if(p[i].ff<=r){
            int k = (r - p[i].ff)/(p[i].ff - p[i].ss) + 1;
            ans += k;
            r -= (p[i].ff - p[i].ss)*k;
        }
    }

    cout<<ans<<endl;
    


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        testcase();
    }
}