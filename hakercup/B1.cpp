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

const int mod = 1e9 + 7;

void testcase(int c)
{
    int n;
    cin>>n;
    int sqx=0,sqy=0,x=0,y=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        sqx = (sqx + (a*a)%mod)%mod;
        sqy = (sqy + (b*b)%mod)%mod;
        x = (x+a)%mod;
        y = (y+b)%mod;
    }

    int q;
    cin>>q;
    int ans1 = 0;
    while(q--){
        int a,b;
        cin>>a>>b;

        int ans = (n*((a*a)%mod))%mod;
        ans = (ans + (n*((b*b)%mod))%mod);
        ans = (ans + (sqx+sqy)%mod)%mod;
        ans = (ans + mod - (2*((x*a)%mod))%mod)%mod;
        ans = (ans + mod - (2*((y*b)%mod))%mod)%mod;

        ans1 = (ans1 + ans)%mod;

    }

    cout<<"Case #"<<c<<": "<<ans1<<endl;

    return;

    
}

signed main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;cin >> t;
    for(int i=0;i<t;i++){
        testcase(i+1);
    }
}