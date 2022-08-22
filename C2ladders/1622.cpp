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

    sort(a,a+n);

    int mp = k/n;

    int sum = 0;
    FOR(i,0,n) sum+=a[i];

    int cost = 0;
    if(a[0]>mp){
        cost = a[0] - mp;
        a[0] = mp;
        sum -= cost;
    }
    int captures = 0;
    int i=n-1;

    while(sum>k){
        if(a[i]-a[0] <= captures+1){
            a[0]--;
            cost++;
            sum = sum - captures - 1;
        }else{
            cost++;
            sum = sum - a[i] + a[0];
            i--;
            captures++;
        }
    }

    cout<<cost<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}