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

    int bin[32]={0},bina[n][32];
    memset(bina,0,sizeof(bina));
    for(int i=0;i<n;i++){
        int temp=a[i];
        int j=0;
        while(temp){
            bin[j] += temp%2;
            bina[i][j] = temp%2;
            temp/=2;
            j++;
        }
    }

    // FOR(i,0,32) cout<<bin[i]<<" ";

    bool poss = false;
    int index=-1;
    for(int i=0;i<32;i++){
        if(bin[i]>1){
            index=i;
            poss=true;
            break;
        }
    }

    if(poss){
        vector<pii> ans;
        ans.pb({1,1});
        int temp=0;
        temp+=bina[0][index];
        for(int i=1;i<n;i++){
            if(temp==bin[index]){
                ans[ans.size()-1].second++;
            }
            else if(bina[i-1][index]==1){
                ans.pb({i+1,i+1});
            }else{
                ans[ans.size()-1].second++;
            }
            temp+=bina[i][index];
        }
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        for(auto i:ans){
            cout<<i.ff<<" "<<i.ss<<endl;
        }
    }else{
        cout<<"NO"<<endl;
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