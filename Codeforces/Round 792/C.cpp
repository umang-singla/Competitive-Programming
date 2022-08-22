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
    int a[n][m],b[n][m];

    FOR(i,0,n){
        FOR(j,0,m){
            int temp;
            cin>>temp;
            a[i][j] = temp;
            b[i][j] = temp;
        }
        sort(b[i],b[i]+m);
    }

    // FOR(i,0,n){
    //     FOR(j,0,m){
    //         cout<<a[i][j].first<<" ";
    //     }
    //     cout<<endl;
    // }

    vector <int> v[n];
    FOR(i,0,n){
        FOR(j,0,m){
            if(a[i][j] != b[i][j]){
                v[i].pb(j);
            }
        }
    }

    int x=-1,y=-1;
    bool poss = true,is_sorted=true;

    vi sorti;

    FOR(i,0,n){
        // cout<<v[i].size()<<endl;
        if(v[i].size() > 2){
            poss = false;
            is_sorted = false;
        }else if(v[i].size()>0){
            sort(all(v[i]));
            // cout<<v[i][0]<<" "<<v[i][1]<<endl;
            is_sorted = false;
            if(x==-1){
                x = v[i][0];
                y = v[i][1];
            }else{
                if(x!=v[i][0] || y!= v[i][1]){
                    poss = false;
                }
            }
        }else{
            // if(x!=-1) poss=false;
            sorti.pb(i);
        }
    }

    if(x!=-1){
        // cout<<poss<<endl;
        for(auto i:sorti){
            // cout<<i<<" ";
            // cout<<x<<" "<<y<<endl;  
            if(a[i][x]!=a[i][y]){
                poss = false;
                break;
            }
        }
    }

    if(is_sorted){
        cout<<1<<" "<<1<<endl;
    }
    else if(poss){
        cout<<x+1<<" "<<y+1<<endl;
    }else{
        cout<<-1<<endl;
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