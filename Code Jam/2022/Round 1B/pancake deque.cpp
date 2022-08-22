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

    int n;
    cin>>n;
    int d[n];

    FOR(i,0,n){
        cin>>d[i];
    }

    int i=0,j=n-1;

    vector <int> v;
    while(i<=j){
        if(d[i]>d[j]){
            v.pb(d[j]);
            j--;
        }
        else{
            v.pb(d[i]);
            i++;
        }
    }

    int ans = 1,max = v[0];
    for(int i=1;i<v.size();i++){
        if(v[i]>=max){
            max = v[i];
            ans++;
        }
    }

    cout<<"Case #"<<c+1<<": "<<ans<<endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        testcase(i);
    }
}