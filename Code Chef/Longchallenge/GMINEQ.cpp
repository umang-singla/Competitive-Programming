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

void testcase(){
    int n;
    cin>>n;
    int a[n];
    FOR(i,0,n){
        cin>>a[i];
    }
    int one=0,nimus_one=0;

    FOR(i,0,n){
        if(a[i]==1)
            one++;
        else
            nimus_one++;
    }

    int k1 = n/2;
    int k2 = n - k1;

    if(one == k1/2 + k2/2 || one == k1 - k1/2 + k2/2 || one == k1 - k1/2 + k2 - k2/2)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

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