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

int lcm(int a,int b){
    return (a*b)/__gcd(a,b);
}

void testcase()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    int p[n];
    FOR(i,0,n) cin>>p[i];

    vector<string> v;
    vector< vector<int> > graph(n);
    FOR(i,0,n){
        // cout<<'a';
        graph[p[i]-1].push_back(i);
        graph[i].push_back(p[i]-1);
    }
    // cout<<'a';
    FOR(i,0,n) sort(graph[i].begin(),graph[i].end());

    int visited[n]={0};

    // if(n>=6)cout<<graph[6][0]<<" "<<graph[6][1];

    FOR(i,0,n){
        if(!visited[i]){
            string temp="";
            temp += s[i];
            visited[i]=1;
            stack<int> st;
            st.push(i);
            while (!st.empty())
            {
                int curr = st.top();
                st.pop();
                for(auto j:graph[curr]){
                    if(!visited[j]){
                        temp+=s[j];
                        visited[j]=1;
                        st.push(j);
                        break;
                    }
                    // break;
                }
            }
            v.push_back(temp);
        }
    }

    int ans=1;

    for(auto t:v){
        // cout<<t<<endl;
        int l = t.size();
        int lps[l+1];
        lps[0]=-1;
        int i=0,j=-1;
        while (i<l)
        {
            while(j!=-1&&t[i]!=t[j]) j = lps[j];
            i++;j++;lps[i]=j;
        }
        int p = l - lps[l];

        // FOR(i,0,l+1) cout<<lps[i]<<" ";
        // cout<<p<<endl;

        if(l%p==0) ans = lcm(ans,p);
        else ans = lcm(ans,l);
        
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