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
    int n,k,b,s;
    cin>>n>>k>>b>>s;

    int m = k*b, M = (k-1)*(n-1) + k*b + k-1;

    if(s<m||s>M) cout<<-1<<endl;
    else{
        int a[n];
        memset(a,0,sizeof(a));

        a[0] = min(s,k*b + k-1);
        s -= min(s,k*b + k-1);

        for(int i=1;i<n;i++){
            a[i]= min(s,k-1);
            s -= min(s,k-1);
        }

        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }

    return ;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}