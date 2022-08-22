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

    vector<vi> graph(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a-1].pb(b-1);
        graph[b-1].pb(a-1);
    }

    //bfs;
    int dp[n];

    memset(dp,-1,sizeof(dp));

    queue <int> q;
    q.push(0);
    dp[0] = 0;
    while (!q.empty())
    {
        // cout<<'a';
        int curr = q.front();
        q.pop();
        for(int i=0;i<graph[curr].size();i++){
            if(dp[graph[curr][i]]==-1){
                dp[graph[curr][i]] = curr;
                q.push(graph[curr][i]);
            }
        }
    }

    // cout<<'a';

    // for(int i=0;i<n;i++) cout<<dp[i]<<" ";

    vi path;

    if(dp[n-1]!=-1){
        int curr = n-1;
        while(dp[curr]!=curr){
            path.pb(curr);
            curr = dp[curr];
        }
        path.pb(0);
        cout<<path.size()<<endl;
        for(auto it = path.rbegin();it!=path.rend();it++){
            cout<<*it + 1<<" ";
        }
        cout<<endl;
    }else cout<<"IMPOSSIBLE"<<endl;
    





}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}