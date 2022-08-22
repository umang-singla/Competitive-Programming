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
    string a[8];
    FOR(i,0,8) cin>>a[i];
    pii ans;

    FOR(i,1,7){
        FOR(j,1,7){
            if(a[i][j]=='#'&&a[i+1][j+1]=='#'&&a[i+1][j-1]=='#'&&a[i-1][j+1]=='#'&&a[i-1][j-1]=='#'){
                ans.ff = i;
                ans.ss = j;
            }
        }
    }

    cout<<ans.ff+1<<" "<<ans.ss+1<<endl;






}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}