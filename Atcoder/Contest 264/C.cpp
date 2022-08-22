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
    int h1,w1;
    cin>>h1>>w1;
    int a[h1][w1];
    for(int i=0;i<h1;i++){
        for(int j=0;j<w1;j++) cin>>a[i][j];
    }

    int h2,w2;
    cin>>h2>>w2;
    int b[h2][w2];
    for(int i=0;i<h2;i++){
        for(int j=0;j<w2;j++){
            cin>>b[i][j];
        }
    }

    int mask1=0,mask2=0;

    bool ans = false;

    for(mask1=0;mask1<(1<<(h1));mask1++){
        for(mask2=0;mask2<(1<<(w1));mask2++){
            vector<int> row,col;
            int it=0;
            int temp = mask1;
            while (temp)
            {
                if(temp%2){
                    row.push_back(it);
                }
                temp/=2;
                it++;
            }
            it=0;temp=mask2;
            while (temp)
            {
                if(temp%2){
                    col.push_back(it);
                }
                temp/=2;
                it++;
            }
            if((int)row.size()!=h2||(int)col.size()!=w2) continue;

            int arr[row.size()][col.size()];
            int p=0,q=0;
            for(auto i:row){
                q=0;
                for(auto j:col){
                    arr[p][q] = a[i][j];
                    q++;
                }
                p++;
            }

            bool equal  =true;

            // cout<<arr[0][0]<<" ";
            for(int i=0;i<row.size();i++){
                for(int j=0;j<col.size();j++){
                    if(arr[i][j]!=b[i][j]){
                        equal=false;
                        // cout<<mask1<<" "<<mask2<<endl;
                        break;
                    }
                }
            }

            if(equal) ans=1;

        }
    }

    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}