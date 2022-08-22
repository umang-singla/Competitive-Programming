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

    string field[n];
    FOR(i,0,n) cin>>field[i];

    int x,y;
    bool done = false;
    FOR(i,0,m){
        FOR(j,0,n){
            if(field[j][i]=='R'){
                x = j;
                y = i;
                done = true;
                break;
            }
        }
        if(done) break;
    }

    bool poss = true;

    FOR(i,0,x){
        FOR(j,0,m){
            if(field[i][j] == 'R') poss = false;
        }
    }

    if(poss) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}