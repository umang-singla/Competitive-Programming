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
    int n,q;
    cin>>n>>q;

    int a[n];
    FOR(i,0,n) cin>>a[i];

    int sum=0;
    FOR(i,0,n) sum+=a[i];

    map <int,int> m;

    bool two = false;
    int prev_x=-1;

    while(q--){
        int t;
        cin>>t;
        int prev = -1;
        if(t==1&&!two){
            int i,x;
            cin>>i>>x;

            sum = sum - a[i-1] + x;
            a[i-1] = x;

        }else if(t==1&&two){
            int i,x;
            cin>>i>>x;

            if(m[i-1]==0){
                // cout<<prev_x<<" ";
                sum -= prev_x;
                sum+=x;
                m[i-1] = x;
            }else{
                sum = sum - m[i-1] + x;
                m[i-1] = x;
            }

        }else{
            int x;
            cin>>x;
            
            sum = n*x;
            prev_x = x;
            // cout<<prev_x<<" ";
            m.clear();
            two=true;
        }
        cout<<sum<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}