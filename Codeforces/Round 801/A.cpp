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
    int n,m;
    cin>>n>>m;

    int a[n][m];
    FOR(i,0,n){
        FOR(j,0,m) cin>>a[i][j];
    }

    int m1 = -1e9 - 1;
    int i1=-1,j1 = -1;

    FOR(i,0,n){
        FOR(j,0,m){
            if(a[i][j]>m1){
                m1 = a[i][j];
                i1 = i;
                j1 = j;
            }
        }
    }
    // cout<<i1<<" "<<j1<<endl;
    cout<< max(i1+1,n-i1)*max(j1+1,m-j1)<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}