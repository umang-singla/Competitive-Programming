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
    int x[n];
    FOR(i,0,n) cin>>x[i];

    map<int,vector<int>> m;
    FOR(i,0,n) m[x[i]].pb(i);

    int val=-1,lo=-1,hi=-1;
    int profit = 0;
    for(auto v:m){
        vi temp;
        temp.pb(1);
        for(int i=1;i<v.ss.size();i++){
            temp.pb(-1*(v.ss[i]-v.ss[i-1]-1));
            temp.pb(1);
        }

        int max_sum=0,sum=0,st=0,ed=0,i_temp=0;
        for(int i = 0;i<temp.size();i++){
            if(sum+temp[i]<=0){
                sum = 0;
            }
            if(sum ==0 &&temp[i]==1){
                i_temp = i;
            }
            if(sum+temp[i]>max_sum){
                max_sum = sum + temp[i];
                st = i_temp;
                ed = i;
            }
            sum+=temp[i];
        }

        if(max_sum>profit){
            profit = max_sum;
            val = v.ff;
            lo = v.ss[st/2];
            hi  = v.ss[ed/2];
        }
        // if(v.ff==6) cout<<max_sum<<endl;


    }
    cout<<val<<" "<<lo+1<<" "<<hi+1<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}