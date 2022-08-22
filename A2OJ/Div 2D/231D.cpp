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
    int x,y,z;
    cin>>x>>y>>z;
    int x1,y1,z1;
    cin>>x1>>y1>>z1;
    int a[6];
    FOR(i,0,6) cin>>a[i];

    int ans = 0;

    if(-1*y > 0) ans+=a[0];
    if(y - y1 > 0) ans+=a[1];
    if(-1*z > 0) ans+=a[2];
    if(z - z1 > 0) ans+=a[3];
    if(-1*x > 0) ans+=a[4];
    if(x - x1 > 0) ans+=a[5];

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