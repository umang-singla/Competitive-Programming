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

void testcase(int c){
    ll r,a,b;
    cin>>r>>a>>b;
    double ans = 0;
    while (r)
    {
        ans += M_PI * r * r;
        r*=a;
        ans += M_PI * r * r;
        r/=b;
    }
    
    cout<<setprecision(6)<<fixed;
    cout<<"Case #"<<c+1<<": "<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    FOR(i, 0, t){
        testcase(i);
    }
}