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
    int a[n],b[n];
    FOR(i,0,n) cin>>a[i];
    FOR(i,0,n) cin>>b[i];

    int index=-1;
    // sort(b,b+n);
    // sort(a,a+n);

    FOR(i,0,n){
        if(b[i]>0){
            index=i;
            break;
        }
    }

    bool poss = true;
    if(index>=0){
        // cout<<index;
        int diff = a[index] - b[index];
        if(diff<0) poss = false;
        FOR(i,0,n){
            if(b[i]==0){
                if(a[i]-b[i]>diff) poss=false;
            }else{
                if(a[i]-b[i]!=diff) poss = false;
            }
        }
        if(poss) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }else cout<<"YES"<<endl;



}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}