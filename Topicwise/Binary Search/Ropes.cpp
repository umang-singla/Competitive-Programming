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
    // FOR(i,0,n) a[i]*=10000000;

    double st=0,ed=1e8;
    cout<<setprecision(20);
    for(int i=0;i<100;i++){
        double mid = (st+ed)/2;

        int cnt=0;
        FOR(i,0,n){
            cnt += floor(a[i]/mid);
        }

        if(cnt<k) ed = mid;
        else st = mid;
    }

    cout<<st<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}