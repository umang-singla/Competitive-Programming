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

    int p[n];
    FOR(i, 0, n)
    {
        cin>>p[i];
    }


    int a[n][n];

    memset(a,0,sizeof(a));

    bool poss = true;
     
    for(int i=0;i<n;i++){
        a[i][i] = p[i];
        int x = i,y=i;
        for(int j=0;j<p[i]-1;j++){
            if(y>0&&a[x][y-1]==0){
                y--;
                a[x][y] = p[i];
            }else if(x<n&&a[x+1][y]==0){
                x++;
                a[x][y] = p[i];
            }else if(y<n&&a[x][y+1]==0){
                y++;
                a[x][y] = p[i];
            }else if(x>0&&a[x-1][y]==0){
                x--;
                a[x][y] = p[i];
            }else{
                poss = false;
                break;
            }
        }
        // cout<<x<<" "<<y<<endl;

        if(!poss)
            break;
    }

    if(poss){
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }else cout<<-1<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}