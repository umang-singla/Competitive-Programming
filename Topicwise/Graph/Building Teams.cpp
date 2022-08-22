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
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a-1].pb(b-1);
        graph[b-1].pb(a-1);
    }

    int team = 1;
    int visited[n]={0};

    bool poss = true;

    for(int i=0;i<n;i++){
        if(visited[i]==0){
            visited[i] = team;
            queue <int> q;
            q.push(i);
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                team = 3 - visited[curr];
                for(int i=0;i<graph[curr].size();i++){
                    if(visited[graph[curr][i]]==0){
                        visited[graph[curr][i]] = team;
                        q.push(graph[curr][i]);
                    }else if(visited[curr] == visited[graph[curr][i]]){
                        poss = false;
                    }
                }
            }
        }
    }

    // for(int i=0;i<n;i++)

    if(poss){
        for(int i=0;i<n;i++) cout<<visited[i]<<" ";
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