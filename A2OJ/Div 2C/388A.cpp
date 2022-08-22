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

#define int long long int

using namespace std;

bool comparator(const vi &a,const vi &b) {
    return a.size() < b.size();
}

void testcase(){

    int n = 100;
    cin>>n;
    int a[n] = {0};
    FOR(i, 0, n){
        cin>>a[i];
    }

    sort(a,a+n);

    vector <vector<int>> v;

    v.pb(vector<int>(1,a[0]));

    FOR(i,1,n){
        sort(all(v),comparator);
        if(v[0].size()<=a[i]){
            v[0].pb(a[i]);
        }
        else{
            v.pb(vector<int>(1,a[i]));
            // cout<<i<<" ";
        }
    }

    cout<<v.size()<<endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    // cin>>t;
    while(t--){
        testcase();
    }
}