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

    int one = 0,zero=0;
    bool compelete = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j] == '1') one++;
            else{
                zero++;
                if(j<m-1&&s[i][j+1]=='0') compelete=true;
                if(i<n-1&&s[i+1][j]=='0') compelete = true;
            }

            if(j<m-1&&i<n-1&&s[i][j+1]=='0'&&s[i+1][j]=='0') compelete = true;
            if(j<m-1&&i<n-1&&s[i][j]=='0'&&s[i+1][j+1]=='0') compelete = true;
        }
    }
    if(one==0){
        cout<<0<<endl;
    }else{
        if(zero == 0){
            cout<<one-2<<endl;
        }else{
            // cout<<'a';
            if(compelete){
                cout<<one<<endl;
            }else{
                cout<<one-1<<endl;
            }
        }
    }
    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}