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
    int n,k;
    cin>>n>>k;

    if(k<=n) cout<<k<<endl;
    else{
        int power = 1;
        while(n*((1<<power) - 1) <=k) power++;

        power--;
        int temp = (1<<power);

        // cout<<power<<" ";

        temp--;

        int ans=0;

        ans += n*(power);

        k-= n*temp;

        // power++;

        ans += k/(1<<power);
        // cout<<ans<<" ";

        k = k%(1<<power);

        temp = (1<<(power))-1 + k;

        while(temp){
            ans += temp%2;
            temp/=2;
        }

        ans -= (power);

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