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
    string s;
    cin>>s;
    int k;
    cin>>k;
    bool c[26] = {0};
    FOR(i,0,k){
        char a;
        cin>>a;
        c[a-'a'] = 1;
    }

    int ans = 0;
    int i = n-1;
    for(;i>=0;i--){
        if(c[s[i]-'a']) break;
    }
    int index = 0;
    while(i>=0){
        if(index > ans){
            ans++;
            index++;
        }
        if(c[s[i]-'a']){
            index = 0;
        }
        index++;
        i--;
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