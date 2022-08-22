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
#define vvi vector << vi >>
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
    int n, m;
    cin >> n >> m;

    string s[n];
    FOR(i, 0, n)
        cin >> s[i];

    int cnt = 0;

    vector<vi> graph(n * m);

    int b=-1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if(s[i][j]=='B') b=i*m+j;
            if (s[i][j] != '#')
            {
                cnt++;
                if (i > 0 && s[i - 1][j] != '#')
                {
                    graph[i * m + j].pb((i - 1) * m + j);
                }
                if (i < n - 1 && s[i + 1][j] != '#')
                {
                    graph[i * m + j].pb((i + 1) * m + j);
                }
                if (j > 0 && s[i][j - 1] != '#')
                {
                    graph[i * m + j].pb(i * m + j - 1);
                }
                if (j < m - 1 && s[i][j + 1] != '#')
                {
                    graph[i * m + j].pb(i * m + j + 1);
                }
            }
        }
    }

    int visited[n * m] = {0};

    int dp[n*m] = {0};

    // int ans = 0;


    for (int i = 0; i < n * m; i++)
    {
        queue<int> st;


        if (s[i / m][i % m] == 'A')
        {
            // cout<<it->ff<<" ";
            // ans++;
            st.push(i);
            int curr = i;

            while (!st.empty())
            {
                curr = st.front();
                visited[curr] = 1;
                st.pop();
                for (auto i : graph[curr])
                {
                    if (visited[i] == 0)
                    {
                        dp[i] = curr;
                        st.push(i);
                        visited[i] = 1;
                    }
                }
            }

            break;
        }
    }

    // cout<<'a';


    if(visited[b])
    {
        cout<<"YES"<<endl;
        string path="";
        int curr = b;
        while(s[curr/m][curr%m] != 'A' ){
            int parent_x = dp[curr]/m,parent_y = dp[curr]%m;
            int x = curr/m,y = curr%m;
            if(x>parent_x) path+="D";
            else if(x<parent_x) path+="U";
            else if(y>parent_y) path+="R";
            else if(y<parent_y) path+="L";
            curr = dp[curr];
        }
        cout<<path.length()<<endl;
        for(auto it = path.rbegin();it!=path.rend();it++){
            cout<<*it;
        }
    }
    else{
        cout<<"NO"<<endl;
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