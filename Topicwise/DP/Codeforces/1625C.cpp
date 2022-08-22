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
    int n,l,k;
    cin>>n>>l>>k;

    int d[n];
    int a[n];
    FOR(i,0,n) cin>>d[i];
    FOR(i,0,n) cin>>a[i];

    bool done[n]={0};

    FOR(i,0,k){
        int prev= a[0];
        int index=0,profit=0;
        FOR(j,1,n-1){
            if(!done[i]){
                if(a[i]>prev){
                    int temp = (d[i+1]-d[i])*(a[i]-prev);
                    if(temp>profit){
                        index = i;
                        profit = temp;
                    }
                }
                prev = a[i];
            }
        }
        if(!done[n-1]){
            if(a[n-1]>prev){
                int temp = (l-d[n-1])*(a[n-1]-prev);
                if(temp>profit){
                    index = n-1;
                    profit = temp;
                }
            }else prev = a[n-1];
        }

        if(index !=0){
            done[index]=1;
        }
    }

    vector<pii> ans;
    FOR(i,0,n){
        if(!done[i]){
            ans.pb({d[i],a[i]});
        }
    }

    int cnt = 0;
    FOR(i,0,ans.size()-1){
        cnt += ans[i].ss*(ans[i+1].ff-ans[i].ff);
    }
    cnt += ans[ans.size()-1].ss*(l-ans[ans.size()-1].ff);

    cout<<cnt<<endl;



}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}