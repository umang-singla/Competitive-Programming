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

    int sum = 0;
    FOR(i,0,n) sum += a[i];

    int prefix[n+1]={0};
    prefix[0]=0;
    for(int i=0;i<n;i++) prefix[i+1]=prefix[i]+a[i];

    bool poss = true;

    if(sum != 0)cout<<"NO"<<endl;
    else{
        int index=-1;
        FORr(i,n-1,0) if(a[i]!=0){
            index=i;
            break;
        }

        if(index==-1) cout<<"YES"<<endl;
        else{
            int p[n]={0};
            for(int i=0;i<index;i++) p[i]=1;
            for(int i=index;i>0;i--){
                int diff = p[i]-a[i];
                // cout<<diff<<" ";
                if(diff<=0) poss = false;
                p[i] = a[i];
                p[i-1] += (diff-1);
            }
            // FOR(i,0,n) cout<<p[i]<<" ";
            if(a[0]!=p[0]) poss = false;
            if(poss)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
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