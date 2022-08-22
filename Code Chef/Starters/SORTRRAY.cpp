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

    int a[n];
    FOR(i,0,n) cin>>a[i];

    vector<vector<int>> ans;

    int m1=a[0],m2=a[0];
    FOR(i,0,n){
        m1 = max(m1,a[i]);
        m2 = min(m2,a[i]);
    }

    int gap = (m1-m2) + 1;

    int power = 1;
    // cout<<();
    while (power<n)
    {
        int j=power;
        vector<int> v;
        


        int k = max(0LL,a[power-1]-a[power]+1);

        while (j<n)
        {
            for(int i=0;i<power&&j+i<n;i++){
                a[j+i] += gap;
                v.pb(j+i+1);
            }
            j += power+1;
        }

        vector<int> temp;
        temp.pb((int)v.size());
        temp.pb(gap);
        ans.pb(temp);
        ans.pb(v);  

        power*=2;

        gap += (m1-m2+1); 

    }

    cout<<ans.size()/2<<endl;
    for(auto i:ans){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
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