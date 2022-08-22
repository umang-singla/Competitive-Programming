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

    int a[n];
    FOR(i,0,n) cin>>a[i];

    set<int> s;
    s.insert(0);
    int mi = a[0];

    FOR(i,1,n){
        if(a[i]<mi){
            s.insert(i);
            mi = a[i];
        }
    }

    while (m--)
    {
        // for(auto i:s) cout<<i<<" ";
        // cout<<endl;
        int k,d;
        cin>>k>>d;

        auto it = s.upper_bound(k-1);

        it--;

        int i = *it;

        if(a[*it] > a[k-1]-d){
            s.insert(k-1);
            i = k-1;
        }
        it = s.upper_bound(i);


        while(it != s.end()){
            int i = *it;
            if(a[*it] >= a[k-1] - d){
                s.erase(*it);
                // s.insert(k-1);
            }else break;
            it = s.upper_bound(i);
        }

        a[k-1]-=d;
        cout<<s.size()<<" ";
    }
    cout<<endl;
    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}