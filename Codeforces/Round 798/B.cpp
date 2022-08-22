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
    int p[n];
    FOR(i,0,n) cin>>p[i];

    if(n==1) cout<<-1<<endl;
    else{
        int ans[n];
        int a[n+1]={0};
        int m = n;
        for(int i=0;i<n;i++){
            m=n;
            for(int j=0;j<n;j++){
                if(j!=i&&a[p[j]]==0) m = min(m,p[j]);
            }
            ans[i] = m;
            a[m] = 1;
        }
        if(ans[n-1]==p[n-1]) swap(ans[n-1],ans[n-2]);
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}