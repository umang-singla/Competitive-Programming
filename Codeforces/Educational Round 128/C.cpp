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
    string s;
    cin >> s;

    int n = s.length();

    int zero[n];
    if(s[0]=='0') zero[0]=1;
    else zero[0] = 0;
    FOR(i,1,n){
        if(s[i]=='0') zero[i] = 1+ zero[i-1];
        else zero[i] = zero[i-1];
    }

    int prefix[n],suffix[n];

    if(s[0]=='0'){
        prefix[0] = 0;
    }else prefix[0] = 1;

    FOR(i,1,n){
        if(s[i]=='1') prefix[i] = 1+ prefix[i-1];
        else prefix[i] = prefix[i-1];
    }

    if(s[n-1]=='0') suffix[n-1]=0;
    else suffix[n-1] = 1;

    FORr(i,n-2,0){
        if(s[i]=='1') suffix[i] = 1 + suffix[i+1];
        else suffix[i] = suffix[i+1];
    }

    // FOR(i,0,n) cout<<prefix[i]<<" ";
    // cout<<endl;
    // FOR(i,0,n) cout<<suffix[i]<<" ";
    // cout<<endl;

    int l = n - zero[n-1];
    // cout<<l<<" ";
    if(l!=n) {
        int ans = max(zero[l-1],suffix[l]);
        FOR(i,1,n-l){
            ans = min(ans,max(prefix[i-1]+suffix[i+l],zero[i+l-1]-zero[i-1]));
        }
        ans = min(ans,max(prefix[n-l-1],zero[n-1]-zero[n-l-1]));
        cout<<ans<<endl;
    }else{
        cout<<0<<endl;
    }



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