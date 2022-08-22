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

#define mod 1000000007

using namespace std;

void testcase()
{
    int n;
    cin>>n;

    int a[n],b[n],d[n];
    FOR(i,0,n) cin>>a[i];
    FOR(i,0,n) cin>>b[i];
    FOR(i,0,n) cin>>d[i];

    vector <vi> graph(n);
    FOR(i,0,n){
        // cout<<a[i]<<" "<<b[i]<<endl;
        graph[a[i]-1].pb(b[i]-1);
        graph[b[i]-1].pb(a[i]-1);
    }

    // for(int i=0;i<n;i++){
    //     for(auto c:graph[i]){
    //         cout<<c<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<'a';

    int ans = 1;

    int visited[n]={0};
    memset(visited,-1,sizeof(visited));

    for(int i=0;i<n;i++){
        if(visited[i]==-1){
            stack <int> st;
            st.push(i);
            visited[i] = i;
            while (!st.empty())
            {
                int curr = st.top();
                st.pop();
                for(int j=0;j<graph[curr].size();j++){
                    if(visited[graph[curr][j]]==-1){
                        visited[graph[curr][j]] = i;
                        st.push(graph[curr][j]);
                    }
                }
            }
            
        }
    }

    map <int ,vector<int>> m;
    for(int i=0;i<n;i++){
        // cout<<visited[i]<<" ";
        m[visited[i]].pb(i);
    }

    set <int> s;
    for(int i=0;i<n;i++){
        if(d[i]>0){
            s.insert(visited[a[i]-1]);
            // cout<<visited[a[i]-1]<<" ";
        }
    }

    // for(auto i=s.begin();i!=s.end();i++){
    //     cout<<*i<<" ";
    // }

    for(auto i:m){
        // cout<<i.first<<" "<<i.second.size()<<endl;
        bool poss = true;

        
        if(!s.empty()&&s.find(i.first)!=s.end()){
            // cout<<i.first<< " ";
            poss = false;
        }
        // cout<<poss<<endl;
        if(poss){
            // cout<<i.first<<" ";
            if(i.second.size()>=2){
                ans*=2;
            }
            ans = ans%mod;

        }

    }

    cout<<ans<<endl;




}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}