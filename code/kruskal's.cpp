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

vector<int> parent,size;

void makeset(){
    for(auto &i:size) i = 0;
    for(int i=0;i<parent.size();i++) parent[i] = i;
}

int find_set(int a){
    if(a!=parent[a]){
        parent[a] = find_set(parent[a]);
    }
    return parent[a];
}

void union_set(int a,int b){
    if(find_set(a)!=find_set(b)){
        a = find_set(a);
        b = find_set(b);
        if(size[a]>size[b]) swap(a,b);

        parent[a] = b;
        size[b] += size[a];
    }
}

void testcase()
{
    int n;
    cin>>n;
    vector<pair<int,int>> g[n+1];
    parent.resize(n+1);
    size.resize(n+1);
    makeset();
    // cout<<'a';
    int m;
    cin>>m;
    int sum = 0;
    priority_queue<pair<int,pair<int,int>>> pq;
    while(m--){
        int u,v;
        cin>>u>>v;
        int w;
        cin>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        pq.push({-w,{u,v}});
    }

    while (!pq.empty())
    {
        int w = -pq.top().first;
        int u = pq.top().second.first, v=pq.top().second.second;
        pq.pop();

        if(find_set(u)!=find_set(v)){
            sum += w;
            union_set(u,v);
        }
    }

    cout<<sum<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}