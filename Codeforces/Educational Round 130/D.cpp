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

    int query[n][n];
    memset(query,0,sizeof(query));
    query[0][0]=1;
    for(int i=1;i<n;i++){
        cout<<"? 2 1 "<<i+1<<endl;
        cin>>query[0][i];
    }

    vector<char> ans(n);

    cout<<"? 1 1"<<endl;
    cin>>ans[0];

    for(int i=1;i<n;i++){
        if(query[0][i]!=query[0][i-1]){
            cout<<"? 1 "<<i+1<<endl;
            cin>>ans[i];
        }
    }
    // cout<<'a';

    for(int i=1;i<n;i++){
        if(query[0][i]==query[0][i-1]){
            int c[26]={0};
            vi pos;
            FORr(j,i-1,0){
                if(!c[ans[j]-'a']){
                    pos.push_back(j);
                    c[ans[j]-'a']=1;
                }
            }

            sort(pos.rbegin(),pos.rend());
            // for(auto i:pos) cout<<i<<" ";
            // cout<<'a';

            int st = 0,ed = pos.size()-1;
            while(st<ed){
                int mid = (st+ed)/2;

                int temp;
                cout<<"? 2 "<<pos[mid] + 1<<" "<<i+1<<endl;
                cin>>temp;
                // query[mid][i] = temp;

                int diff = mid+2 - temp;
                if(diff>0){
                    ed = mid;
                }else{
                    st = mid + 1;
                }
            }
            ans[i] = ans[pos[st]];
        }
    }

    cout<<"! ";
    for(auto i:ans) cout<<i;
    cout<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}