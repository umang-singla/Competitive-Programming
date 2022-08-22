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
    int n,k;
    cin>>n>>k;

    int a[n];
    FOR(i,0,n) cin>>a[i];

    pair <int,int> p[n];
    FOR(i,0,n) {
        p[i].ff = a[i]+i;
        p[i].ss = i;
    }

    sort(p,p+n);

    pair <int,int> skp[k];

    for(int i=n-1;i>=n-k;i--){
        skp[n-1-i].ff = p[i].ss;
        skp[n-1-i].ss = p[i].ff;
    }

    sort(skp,skp+k);

    int damage=0,skip=0;
    FOR(i,0,n){
        if(i==skp[skip].ff){
            skip++;
        }else{
            damage+=(a[i]+skip);
        }
    }

    cout<<damage<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}