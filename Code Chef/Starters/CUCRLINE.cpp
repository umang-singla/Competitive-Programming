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
#define FOR(i, l, r) for (i = l; i < r; ++i)
#define FORr(i, l, r) for (i = l; i >= r; --i)

#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof ((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c, x)((c).find(x) != (c).end())
#define cpresent(c, x)(find(all(c), x) != (c).end())
#define int long long int

using namespace std;

void testcase(){
    int x,y;
    cin>>x>>y;

    vi factors_of_y,factors_of_x ;

    for(int i=1;i<=sqrt(y);i++){
        if(y%i == 0){
            factors_of_y.pb(i);
            factors_of_y.pb(y/i);
        }
    }

    for(int i=1;i<=sqrt(x);i++){
        if(x%i == 0){
            factors_of_x.pb(i);
            factors_of_x.pb(x/i);
        }
    }

    sort(all(factors_of_y));
    sort(all(factors_of_x));

    set <pair<int,int>> ans;

    for(int i=0;i<factors_of_y.size();i++){
        for(int j=0;j<factors_of_x.size();j++){
            int hcf = __gcd(factors_of_y[i],factors_of_x[j]);
            ans.insert(mp(factors_of_y[i]/hcf,factors_of_x[j]/hcf));
        }
    }

    cout<<ans.size()<<endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int t = 1;
    // cin>>t;
    while(t--){
        testcase();
    }
}