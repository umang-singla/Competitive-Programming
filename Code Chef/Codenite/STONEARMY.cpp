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
    int sum_b=0,sum_a=0;
    FOR(i,0,n){
        cin>>a[i];
        sum_a+=a[i];
    }
    FOR(i,0,n){
        cin>>b[i];
        sum_b += b[i];
    }

    int ans = sum_b*n - sum_a;

    int diff[n];

    FOR(i,0,n){
        diff[i] = a[i] - b[i];
    }

    sort(diff,diff+n);

    FOR(i,0,n){
        ans = ans + diff[i]*(i+1);
    }

    cout<<ans<<endl;


}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}