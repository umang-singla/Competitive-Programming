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
#define mod 1000000007

using namespace std;

void testcase(){

    int n;
    cin >> n;

    int four = 0, seven = 0;
    int a[n+1];

    FOR(i,0,n+1) a[i] = mod;

    a[0] = 0;
    
    FOR(i,1,n+1){
        if(i>=4){
           a[i] = min(1 + a[i-4], a[i]);
        }
        if(i>=7){
            a[i] = min(1 + a[i-7], a[i]);
        }
        // cout<<a[i]<<" ";
    }

    if(a[n] < mod){
        seven = (n - 4*a[n])/3;
        four = a[n] - seven;        
        FOR(i,0,four){
            cout << "4";
        }
        FOR(i,0,seven){
            cout << "7";
        }
    }
    else{
        cout << -1 << endl;
    }

    

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