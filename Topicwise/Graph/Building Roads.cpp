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

    vector <vi> graph(n);

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a-1].pb(b-1);
        graph[b-1].pb(a-1);
    }


    //dfs

    int visited[n]={0};

    vi cmp;

    for(int i=0;i<n;i++){
        if(visited[i]==0){
            cmp.pb(i);
            stack <int> s;

            s.push(i);
            visited[i] = 0;
            while(!s.empty()){
                int curr = s.top();
                s.pop();
                for(int j=0;j<graph[curr].size();j++){
                    if(visited[graph[curr][j]]==0){
                        visited[graph[curr][j]] = 1;
                        s.push(graph[curr][j]);
                    }
                }
            }
        }
    }

    cout<<cmp.size()-1<<endl;
    for(int i=0;i<cmp.size()-1;i++){
        cout<<cmp[i]+1<<" "<<cmp[i+1]+1<<endl;
    }

    // cout<<'a';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}