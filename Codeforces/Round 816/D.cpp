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
    int n,q;
    cin>>n>>q;

    if(n==1){
        cout<<0<<endl;
        return;
    }

    int m = INT_MAX;

    int a[n];
    FOR(i,0,n) a[i]=m;

    vector<int> g[n];

    while(q--){
        int i,j,x;
        cin>>i>>j>>x;
        if(i!=j){
            g[i-1].push_back(j-1);
            g[j-1].push_back(i-1);

            a[i-1] = a[i-1]&x;
            a[j-1] = a[j-1]&x;
        }else{
            a[i-1] = x;
        }
    }

    for(int i=0;i<n;i++){
        for(auto j:g[i]){
            // if(j!=i){
                a[i] = ((a[i]|a[j]) - a[j]);
            // }
        }
    }

    for(int i=0;i<n;i++){
        // cout<<'a';
        if(a[i]==INT_MAX) cout<<0<<" ";
        else cout<<a[i]<<" ";
    }
    cout<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}