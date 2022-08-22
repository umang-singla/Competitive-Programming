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
    int s[n];
    FOR(i,0,n) cin>>s[i];

    bool poss=true;
    vector<int> ans;
    int cnt=1;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            ans.pb(cnt);
            cnt=1;
        }else{
            cnt++;
        }
    }
    ans.pb(cnt);
    for(auto it:ans){
        if(it==1) poss=false;
    }

    if(poss){
        int index=0;
        int i=0;
        while(i<n){
            for(int j=1;j<=ans[index];j++){
                cout<<i+1+j%ans[index]<<" ";
            }
            i += ans[index];
            index++;            
        }
        cout<<endl;
    }else{
        cout<<-1<<endl;
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