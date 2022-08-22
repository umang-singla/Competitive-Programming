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
    cin >> n;

    int p[n+1];
    FOR(i, 1, n+1) cin >> p[i];

    vector <vi> graph(n+1);

    FOR(i, 1, n+1){
        if(p[i] != i){
            graph[p[i]].pb(i);
        }
    }

    vector<vector<int>> paths;

    int visited[n+1]={0};

    FOR(i, 1, n+1){
        if(graph[i].size() == 0){
            int curr = i;
            vector <int> temp;
            while(visited[curr]==0){
                visited[curr] = 1;
                temp.pb(curr);
                curr = p[curr];
            }
            paths.pb(temp);
        }
    }

    cout<<paths.size()<<endl;
    for(auto x:paths){
        cout<<x.size()<<endl;
        for(int i=x.size()-1;i>=0;i--){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;



}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}