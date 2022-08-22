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
    int i,j;
    cin>>i>>j;
    i--;j--;

    int a[15][15];
    int color = 0;

    int p=0,q=0;

    int side = 15;
    while (side>=1)
    {
        // int p = 15-side,q=15-side;
        
        while (q<side+p)
        {
            a[p][q]=color;
            q++;
        }
        q--;
        for(int k=0;k<side;k++){
            a[p][q]=color;
            p++;
        }
        p--;
        for(int k=0;k<side;k++){
            a[p][q]=  color;
            q--;
        }
        q++;
        for(int k=0;k<side;k++){
            a[p][q] = color;
            p--;
        }
        p++;

        side-=2;
        p++;
        q++;
        
        color = 1-color;
    }

    // for(int i=0;i<15;i++){
    //     for(int j=0;j<15;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    if(a[i][j]==0) cout<<"black"<<endl;
    else cout<<"white"<<endl;
    


}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}