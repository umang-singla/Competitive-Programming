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

    string s[n];
    FOR(i,0,n) cin>>s[i];

    int cnt = 0;

    vector <vi> graph(n*m);


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]!='#'){
                cnt++;
                if(i>0&&s[i-1][j]=='.'){
                    graph[i*m+j].pb((i-1)*m+j);
                }
                if(i<n-1&&s[i+1][j]=='.'){
                    graph[i*m+j].pb((i+1)*m+j);
                }
                if(j>0&&s[i][j-1]=='.'){
                    graph[i*m+j].pb(i*m+j-1);
                }
                if(j<m-1&&s[i][j+1]=='.'){
                    graph[i*m+j].pb(i*m+j+1);
                }
            }
        }
    }

    int visited[n*m] = {0};

    int ans=0;

    if(cnt==0){
        cout<<0<<endl;
    }else{
        for(int i=0;i<n*m;i++){
            vector<int> st;

            if(s[i/m][i%m]=='.'&&visited[i]==0){
                // cout<<it->ff<<" ";
                ans++;
                st.pb(i);
                int curr = i;

                while(!st.empty()){
                    curr = st[st.size()-1];
                    visited[curr]=1;
                    st.pop_back();
                    for(auto i:graph[curr]){
                        if(visited[i]==0){
                            st.pb(i);
                        }
                    }
                }

            }
        }
        cout<<ans<<endl;
    }




}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}