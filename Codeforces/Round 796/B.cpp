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

    vi odd,even;
    FOR(i,0,n) {
        if(a[i]%2) odd.pb(a[i]);
        else even.pb(a[i]);
    }

    int s1=odd.size(),s2=even.size();

    if(s1>0){
        cout<<s2<<endl;
    }else{
        int ans = 1e10;

        for(int i=0;i<s2;i++){
            int temp=0;
            while(even[i]%2==0){
                temp++;
                even[i]/=2;
            }
            ans = min(ans,temp);
        }

        ans += (s2 -1);
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