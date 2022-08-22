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

    int ans = (n*(n+1)*(n+2))/6;

    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            ans -= (i)*(n-i);
        }
    }

    // cout<<ans<<endl;

    while(m--){
        int i,x;
        cin>>i>>x;

        i--;

        bool left=false,right=false;
        if(i>0&&a[i]==a[i-1]) left=1;
        if(i<n-1&&a[i]==a[i+1]) right=1;



        int l = 0,r=0;
        a[i]=x;
        if(i>0&&a[i]==a[i-1]) l=1;
        if(i<n-1&&a[i]==a[i+1]) r=1;

        if(!left&&!right){
            // cout<<'a';
            if(!l&&!r){
                ;
            }else if(l&&!r){
                // cout<<'a';
                ans -= (i)*(n-i);
            }else if(!l&&r){
                ans -= (n-i-1)*(i+1);
            }else{
                ans -= (i)*(n-i);
                ans -= (n-i-1)*(i+1);
            }
        }else if(left&&!right){
            if(!l&&!r){
                ans += (i)*(n-i);
            }else if(l&&!r){
                ;
            }else if(!l&&r){
                ans += i*(n-i);
                ans -= (n-i-1)*(i+1);
            }else{
                ans -= (n-i-1)*(i+1);

            }
        }else if(!left&&right){
            if(!l&&!r){
                ans += (i+1)*(n-i-1);
            }else if(l&&!r){
                ans += (i+1)*(n-i-1);
                ans -= i*(n-i);
            }else if(!l&&r){
                ;
            }else{
                ans -= (i)*(n-i);
            }
        }else{
            // cout<<'a';
            if(!l&&!r){
                ans += (i)*(n-i);
                ans += (n-i-1)*(i+1);
            }else if(l&&!r){
                ;
            }else if(!l&&r){
                ;
            }else{
                ;
            }
        }
        // cout<<'a';
        cout<<ans<<endl;
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