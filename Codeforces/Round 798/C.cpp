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

    vector<vector<int>> graph;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        graph[u-1].pb(v-1);
        graph[v-1].pb(u-1);
    }

    int dp[n] = {0};
    memset(dp,-1,sizeof(dp));
    queue<int> q;
    int vertex[n]={0};
    int visited[n]={0};
    FOR(i,1,n){
        if(graph[i].size()==1){
            q.push(i);
            visited[i]=1;

            int curr = i;
            while (curr!=0)
            {
                vertex[graph[curr][0]] += vertex[curr] + 1;
                curr = graph[curr][0];
            }
            
            
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