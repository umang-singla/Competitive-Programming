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

using namespace std;

void testcase(){

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;
    // cin>>t;
    // while(t--){
    //     testcase();
    // }
    int a,b,c,d,e,f,x;
    cin>>a>>b>>c>>d>>e>>f>>x;

    int t = a*(x/(a+c))*b;
    if(x%(b+c)){
        if(x%(a+c)>=a){
            t+=b*a;
        }
        else{
            t+=(x%(a+c))*b;
        }
    }
    int ah = d*(x/(d+f))*e;
    if(x%(e+f)){
        if(x%(d+f)>=d){
            ah+=e*d;
        }
        else{
            ah+=(x%(d+f))*e;
        }
    }

    if(t>ah) cout<<"Takahashi"<<endl;
    else if(ah>t) cout<<"Aoki"<<endl;
    else cout<<"Draw"<<endl;
}