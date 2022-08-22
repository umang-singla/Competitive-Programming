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

    int a[n];
    FOR(i,0,n) cin>>a[i];

    vector<pii> ans;

    vector<int> pos;
    pos.push_back(0);
    FOR(i,1,n){
        if(a[i]<a[i-1]) pos.push_back(i);
    }
    pos.push_back(n);

    for(int i=0;i<n;i++){
        if(a[i]!=i+1){
            int index=-1,k=-1;
            for(int j=0;j<pos.size()-1;j++){
                if(a[pos[j]]==i+1){
                    index=pos[j];
                    k = j;
                    break;
                }
            }
            int index2=-1;
            for(int j=index;j<pos[k+1];j++){
                if(a[i]>a[j]){
                    index2=j;
                }
            }
            // cout<<i<<" "<<index2<<endl;

            while (index2>=index)
            {
                ans.pb({i,index2});
                swap(a[i],a[index2]);
                index2--;
            }
            
        }
    }

    int s = ans.size();

    cout<<s<<endl;
    for(auto i:ans) cout<<i.ff+1<<" "<<i.ss+1<<endl;


}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}