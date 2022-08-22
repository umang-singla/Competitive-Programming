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

void testcase(int c)
{
    int n;
    cin>>n;

    string p;
    cin>>p;

    int lps[n+1];
    lps[0]=-1;
    int i=0,j=-1;

    while(i<n){
        while(j!=-1&&p[i]!=p[j]) j = lps[j];
        i++;j++;lps[i]=j;
    }

    string q = "";
    int index = n;
    int l = n - lps[n];
    if(n%l==0) index = l-1;

    // cout<<index;

    // for(int i=0;i<=n;i++) cout<<lps[i]<<" ";

    if(index == n) q = p;
    else q = p.substr(0,index+1);    

    cout<<"Case #"<<c<<": "<<q<<endl;
}



signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;
    for(int i=0;i<t;i++)
    testcase(i+1);
}