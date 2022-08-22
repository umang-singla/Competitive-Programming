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

    if(n%2){
        cout<<"NO"<<endl;
    }else{
        int b[n];
        int j=n/2-1,i=n-1;
        int index=0;
        sort(a,a+n);
        while(j>=0){
            b[index] = a[i];
            i--;
            index++;
            b[index] = a[j];
            j--;
            index++;
        }
        bool poss = true;
        FOR(i,1,n-1){
            if(!((b[i]>b[i-1]&&b[i]>b[i+1])||(b[i]<b[i-1]&&b[i]<b[i+1]))){
                poss=false;
                break;
            }
        }

        if(poss){
            cout<<"YES"<<endl;
            FOR(i,0,n) cout<<b[i]<<" ";
            cout<<endl;
        }else cout<<"NO"<<endl;
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