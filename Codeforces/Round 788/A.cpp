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
    FOR(i,0,n)cin>>a[i];

    int minus = 0;

    for(int i=0;i<n;i++){
        if(a[i]<0) minus++;
    }

    int i=0,j=n-1;
    while(i<j){
        if(a[i]<0)i++;
        else if(a[j]>0) j--;
        else{
            a[i] = -1*a[i];
            a[j] = -1*a[j];
            i++;
            j--;
        }
    }

    bool sorted = true;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]) {
            sorted = false;
            break;
        }
    }

    if(sorted) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}