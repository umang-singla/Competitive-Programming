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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;

    pair<int,int> a[m];
    string s="";
    for(int i=0;i<m;i++){
        s+='0';
    }

    for(int i=0;i<m;i++){
        s[i]='1';
        cout<<"? "<<s<<endl;
        int temp;
        cin>>temp;
        
        a[i] = mp(temp,i);
        s[i] = '0';
    }

    int ans=0;
    sort(a,a+m);
    for(int i=0;i<m;i++){
        s[a[i].ss]='1';
        cout<<"? "<<s<<endl;
        int temp;
        cin>>temp;
        if(temp == ans + a[i].ff){
            ans += a[i].ff;
        }else{
            s[a[i].ss]='0';
        }
    }

    cout<<"! "<<ans;
    cout.flush();
}