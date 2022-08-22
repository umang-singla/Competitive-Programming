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

    FOR(i,0,n){
        cin>>a[i];
    }

    int op = 0;

    bool poss = true;

    for(int i=n-2;i>=0;i--){

        // cout<<a[i]<<" ";

        // cout<<(a[i+1]>=a[i])<<" ";

        while((a[i]>0)&&(a[i+1]<=a[i])){
            // cout<<a[i]<<" ";
            a[i] = a[i]/2;
            op++;
        }

        // cout<<a[i]<<" ";

        if(a[i]==0&&a[i+1]==0){
            poss = false;
            break;
        }

    }

    if(poss) cout<<op<<endl;
    else cout<<-1<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}