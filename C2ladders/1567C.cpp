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
    string s;
    cin>>s;
    vi a;
    for(auto c:s){
        a.pb(c-'0');
    }
    if(a.size()==1) cout<<a[0]-1<<endl;
    else if(a.size()==2) cout<<(a[0]+1)*(a[1]+1) -2<<endl;
    else{
        int ans = 0;
        for(int i=0;i<a.size();i+=2){
            ans = 10*ans + a[i];
        }
        int temp=0;
        for(int i=1;i<a.size();i+=2){
            temp = 10*temp + a[i];
        }

        ans = (ans+1)*(temp+1);
        ans-=2;
        cout<<ans<<endl;
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