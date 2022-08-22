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
    int x;
    cin>>x;
    int temp=x;
    int a,b;
    int bin[32]={0};
    int i=0;
    int ans=0;
    while(x){
        bin[i]=x%2;
        i++;
        x/=2;
    }

    for(int j=0;i<32;j++){
        if(bin[j]==1){
            a=j;
            break;
        }
    }
    for(int j=0;i<32;j++){
        if(bin[j]==0){
            b=j;
            // cout<<j<<" ";=
            break;
        }
    }


    if(temp - (1<<a) == 0) ans = (1<<a) + (1<<b);
    else ans = (1<<a);
    cout<<ans<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}