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

void testcase(int k)
{
    int r,c;
    cin>>r>>c;

    string s[r];
    FOR(i,0,r) cin>>s[i];
    cout<<"Case #"<<k<<": ";

    if(r==1||c==1){
        bool poss = true;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++) if(s[i][j]=='^') poss = false;
        }
        if(poss){
            cout<<"Possible"<<endl;
                for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    cout<<s[i][j];
                }
                cout<<endl;
            }
        }else{
            cout<<"Impossible"<<endl;
        }
    }else{
        cout<<"Possible"<<endl;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<'^';
            }
            cout<<endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;cin >> t;for(int i=0;i<t;i++)
    testcase(i+1);
}