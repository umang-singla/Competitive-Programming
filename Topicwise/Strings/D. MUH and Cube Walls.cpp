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
    int n,w;
    cin>>n>>w;

    int a[n];
    FOR(i,0,n) cin>>a[i];

    int b[w];
    FOR(i,0,w) cin>>b[i];

    if(w==1){
        cout<<n<<endl;
        return;
    }

    if(n==1){
        cout<<0<<endl;
        return;
    }

    int s[w+n-1];
    FOR(i,0,w-1) s[i]=b[i+1]-b[i];
    s[w-1]=1000000001;
    FOR(i,w,w+n-1) s[i] = a[i-w+1] - a[i-w];

    int lps[w+n];
    lps[0]=-1;
    int i=0,j=-1;
    while(i<w+n-1){
        while(j!=-1&&s[i]!=s[j])j=lps[j];
        i++;j++;lps[i]=j;
    }

    int ans=0;
    FOR(i,w,w+n-1){
        // cout<<lps[i]
        if(lps[i+1]==w-1) ans++;
    }

    cout<<ans<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}