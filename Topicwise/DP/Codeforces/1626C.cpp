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
    int k[n],h[n];
    FOR(i,0,n) cin>>k[i];
    FOR(i,0,n) cin>>h[i];

    pair<int,int> intervals[n];

    FOR(i,0,n){
        intervals[i].ss = k[i];
        intervals[i].ff = k[i] - h[i] + 1;
    }

    sort(intervals,intervals+n);

    vector<pair<int,int>> ans;
    ans.pb(intervals[0]);

    FOR(i,1,n){
        if(intervals[i].ff<=ans[ans.size()-1].ss){
            ans[ans.size()-1].ss = max(intervals[i].ss,ans[ans.size()-1].ss);
        }else{
            ans.pb(intervals[i]);
        }
    }

    int a = 0;

    for(auto i:ans){
        int diff = i.ss - i.ff + 1;
        a += (diff*(diff+1))/2;
    }

    cout<<a<<endl;
    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}