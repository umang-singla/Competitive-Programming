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

using namespace std;

void testcase()
{
    int n,q;
    cin>>n>>q;
    int a[n];
    FOR(i,0,n) cin>>a[i];

    int match = 0;
    deque<int> dq;
    map<int,int> win[n+1];
    // memset(win,0,sizeof(win));
    for(int i=0;i<n;i++){
        dq.push_back(a[i]);
    }

    set<int> lwin[n+1];
    for(int i=0;i<=n;i++) lwin[i].insert(0);

    for(int i=0;i<n;i++){
        match++;
        int a = dq.front();
        dq.pop_front();
        int b = dq.front();
        dq.pop_front();
        if(a>b) swap(a,b);
        win[b][match] = win[b][match-1]+1;
        lwin[b].insert(match);
        // cout<<a<<" "<<b<<endl;
        dq.push_back(a);
        dq.push_front(b);
    }

    while (q--)
    {
        int i,k;
        cin>>i>>k;

        // cout<<'a';

        if(k<=match){
            // cout<<'a';
            // cout<<win[3][2];
            auto it = lwin[a[i-1]].upper_bound(k);
            it--;
            cout<<win[a[i-1]][(*it)]<<endl;
        }else{
            if(a[i-1]==n){
                // cout<<'a';
                auto it = lwin[a[i-1]].upper_bound(match);
                it--;
                int ans = win[a[i-1]][(*it)];
                ans += (k-match);
                cout<<ans<<endl;
            }else{
                // cout<<'a';
                auto it = lwin[a[i-1]].upper_bound(match);
                it--;
                cout<<win[a[i-1]][(*it)]<<endl;
            }
        }
    }
    


}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}