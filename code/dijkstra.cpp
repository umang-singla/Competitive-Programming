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
    vector<pair<int,int>> g[n+1];
    int m;
    cin>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        int w;
        cin>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    int st = 0;
    vector<int> d(n+1,INT_MAX);
    vector<int> parent(n+1,-1);
    d[st] = 0;
    parent[st] = st;
    priority_queue<pair<int,int>> pq;
    pq.push({0,st});
    while(!pq.empty()){
        int cur = pq.top().second;
        pq.pop();
        for(auto to:g[cur]){
            if(to.second + d[cur] < d[to.first]){
                d[to.first] = to.second + d[cur];
                parent[to.first] = cur;
                pq.push({-d[to.first],to.first});
            }
        }
    }

    for(int i=0;i<=n;i++) cout<<i<<" "<<d[i]<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}