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
    int n,k;
    cin>>n>>k;

    if(n%2==0&&k%2==0){

        int a[k];

        FOR(i,0,k-2){
            a[i]=1;
            n-=1;
        }
        a[k-1]=a[k-2]=n/2;
        FOR(i,0,k) cout<<a[i]<<" ";
        cout<<endl;
    }else if(n%2==0&&k%2==1){
        int a[k];
        FOR(i,0,k-3){
            a[i]=1;
            n-=1;
        }
        a[k-3]=a[k-2]=n/2;
        if(a[k-3]%2){
            a[k-3]--;
            a[k-2]--;
            a[k-1] = 2;
        }else{
            a[k-1]=a[k-2]=a[k-2]/2;
        }
        FOR(i,0,k) cout<<a[i]<<" ";
        cout<<endl;
    }else if(n%2==1&&k%2==0){
        int a[k];
        a[0]=1;
        n--;
        FOR(i,1,k-3){
            a[i]=1;
            n-=1;
        }
        a[k-3]=a[k-2]=n/2;
        if(a[k-3]%2){
            a[k-3]--;
            a[k-2]--;
            a[k-1] = 2;
        }else{
            a[k-1]=a[k-2]=a[k-2]/2;
        }
        FOR(i,0,k) cout<<a[i]<<" ";
        cout<<endl;
    }else{
        int a[k];
        a[0]=1;
        n--;

        FOR(i,1,k-2){
            a[i]=1;
            n-=1;
        }
        a[k-1]=a[k-2]=n/2;
        FOR(i,0,k) cout<<a[i]<<" ";
        cout<<endl;

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