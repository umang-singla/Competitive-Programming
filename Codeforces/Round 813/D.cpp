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
    int a[n];
    FOR(i,0,n) cin>>a[i];

    int st = 1,ed = 1e9;
    while(st<ed){
        int ans = (st+ed+1)/2;

        int threshold = (ans+1)/2;

        int op = 0;
        for(int i=0;i<n;i++) if(a[i]<threshold) op++;

        if(op>k){
            ed = ans-1;
        }else{
            // st = ans;
            int b[n];
            FOR(i,0,n) b[i]=a[i];
            FOR(i,0,n) if(b[i]<threshold) b[i] = 1e9;

            bool found1 = false,found2 = false;

            FOR(i,0,n-1){
                if(min(b[i],b[i+1])>=ans) found1 = true;
                if(max(b[i],b[i+1])>=ans) found2 = true;

            }

            if(!found1&&found2) op++;
            else if(!found2) op+=2;

            if(op>k){
                ed = ans - 1;
            }else st = ans;

        }

    }

    cout<<st<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}