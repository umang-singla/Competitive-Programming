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
    int a[n],b[n];
    FOR(i,0,n){
        cin>>a[i];
        b[i] = a[i];
    }

    sort(b,b+n);
    
    int err = 0;

    if(a[0] != b[0]){
        if(a[0] != b[1]){
            cout<<"NO"<<endl;
            return;
        }else{
            err++;
        }
    }

    FOR(i,1,n-1){
        if(a[i] != b[i]){
            if(a[i] == b[i+1] || a[i] == b[i-1])
                err++;
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    if(a[n-1] != b[n-1]){
        if(a[n-1] != b[n-2]){
            cout<<"NO"<<endl;
            return;
        }else{
            err++;
        }
    }

    if(err <=2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return;



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