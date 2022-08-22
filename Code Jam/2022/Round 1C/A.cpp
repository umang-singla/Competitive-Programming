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

using namespace std;

bool isvalid(string s){
    if(s.length()==1) return true;
    else{
        FOR(i,0,s.length()){
            FOR(j,i+1,s.length()){
                if(s[i]==s[j]&&s[j-1]!=s[i]){
                    return false;
                }
            }
        }
        return true;
    }
}

void testcase(int c)
{
    int n;
    cin >> n;
    string s[n];
    FOR(i, 0, n)
    {
        cin >> s[i];
    }

    bool valid = true;

    FOR(i,0,n){
        if(!isvalid(s[i])){
            valid = false;
            break;
        }
    }

    if(!valid){
        cout<<"Case #"<<c<<": IMPOSSIBLE"<<endl;
    }else{
        
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        testcase(i + 1);
    }
}