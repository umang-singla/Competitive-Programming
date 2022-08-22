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

bool isPalindrone(string s){
    if(s[0]==s[4]&&s[1]==s[3]) return true;
    else return false;
}

void testcase(int c)
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool poss = true;
    if(n<5) poss = false;
    else{
        
    }

    if(poss){
        cout<<"Case #"<<c<<": POSSIBLE"<<endl;
    }else{
        cout<<"Case #"<<c<<": IMPOSSIBLE"<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;FOR(i,0,t)
    testcase(i+1);
}