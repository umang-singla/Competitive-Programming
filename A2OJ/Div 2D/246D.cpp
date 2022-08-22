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

    int c[n];
    FOR(i,0,n) cin>>c[i];
    map <int,set<int>> cnt;

    while (m--)
    {
        int a,b;
        cin>>a>>b;
        if(c[a-1]!=c[b-1]){
            cnt[c[a-1]].insert(c[b-1]);
            cnt[c[b-1]].insert(c[a-1]);
        }
    }
    

    sort(c,c+n);
    int ans = c[0];
    
    for(auto i:cnt){
        if(cnt[ans].size()<i.second.size()){
            ans = i.first;
        }
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