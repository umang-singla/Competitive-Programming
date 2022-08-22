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
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    pii st, ed;
    FOR(i, 0, n)
    {
        if (s1[i] == '*')
        {
            st.ff = i;
            st.ss = 1;
            break;
        }
        if (s2[i] == '*')
        {
            st.ff = i;
            st.ss = 2;
            break;
        }
    }

    FORr(i, n - 1, 0)
    {
        if (s1[i] == '*')
        {
            ed.ff = i;
            ed.ss = 1;
            break;
        }
        if (s2[i] == '*')
        {
            ed.ff = i;
            ed.ss = 2;
            break;
        }
    }

    int dp[2][n];
    memset(dp,0,sizeof(dp));

    if(s2[st.ff]=='*') dp[0][st.ff] = 1;
    else dp[0][st.ff] = 0;

    if(s1[st.ff]=='*') dp[1][st.ff] = 1;
    else dp[1][st.ff] = 0;


    FOR(i,st.ff+1,n){
        dp[0][i] = dp[0][i-1]+1;
        if(s2[i]=='*') dp[0][i]++;
        dp[0][i] = min(dp[0][i],dp[1][i-1]+2);

        dp[1][i] = dp[1][i-1] + 1;
        if(s1[i]=='*') dp[1][i]++;
        dp[1][i] = min(dp[1][i],2+dp[0][i-1]);
    }

    // FOR(i,st.ff,ed.ff+1){
    //     cout<<dp[0][i]<<" ";
    // }
    // cout<<endl;
    // FOR(i,st.ff,ed.ff+1){
    //     cout<<dp[1][i]<<" ";
    // }
    // cout<<endl;


    cout<<min(dp[0][ed.ff],dp[1][ed.ff])<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        testcase();
}