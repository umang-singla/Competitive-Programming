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

void testcase(int c)
{
    int n;
    cin>>n;
    int a[n];
    FOR(i,0,n) cin>>a[i];
    int m;
    cin>>m;
    int b[m];
    FOR(i,0,m) cin>>b[i];
    int k;
    cin>>k;

    int prefixa[n+1],prefixb[m+1];

    prefixa[0] = 0;
    for(int i=0;i<n;i++) prefixa[i+1] = prefixa[i] + a[i];
    prefixb[0] = 0;
    for(int i=0;i<m;i++) prefixb[i+1] = prefixb[i] + b[i];

    int ans = 0;

    for(int i=0;i<=min(n,k);i++){
        if(k - i <= m){
            int s1=0,s2=0;
            for(int j=i;j>=0;j--){
                s1 = max(s1,prefixa[j] + prefixa[n] - prefixa[n - (i-j)]);
            }
            for(int j=k-i;j>=0;j--){
                s2 = max(s2,prefixb[j] + prefixb[m] - prefixb[m - (k-i-j)]);
            }

            ans = max(ans,s1+s2);
        }
    }
    

    

    cout<<"Case #"<<c<<": "<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;
    for(int i=0;i<t;i++) testcase(i+1);
}