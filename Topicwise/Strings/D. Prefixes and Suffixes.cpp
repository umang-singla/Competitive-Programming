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
    string s;
    cin>>s;

    int lps[s.length()+1];

    int i=0,j=-1;
    lps[0]=-1;
    while(i<s.length()){
        while(j!=-1&&s[i]!=s[j]) j = lps[j];
        i++;j++;lps[i]=j;
    }

    // FOR(i,0,s.length()+1) cout<<lps[i]<<" ";
    // cout<<endl;

    //aaaabaaaa

    int ans[s.length()+1]={0};
    FORr(i,s.length(),1){
        ans[lps[i]] += ans[i] + 1;
    }

    vector<pii>v;

    j=lps[s.length()];
    v.pb({j,ans[j]+1});
    j = lps[j];
    while(j>0){
        v.pb({j,ans[j]+1});
        j=lps[j];
    }
    int size=0;
    FOR(i,0,v.size()) if(v[i].ff>0) size++;
    cout<<size+1<<endl;
    FORr(i,v.size()-1,0){
        if(v[i].ff>0) cout<<v[i].ff<<" "<<v[i].ss<<endl;
    }
    cout<<s.length()<<" "<<1<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}