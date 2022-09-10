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
    // cout<<'a';
    int n,k;
    cin>>n>>k;
    int a[n],b[n];
    FOR(i,0,n) cin>>a[i];
    FOR(i,0,n) cin>>b[i];

    bool poss = true;

    int index = 0;
    for(int i=0;i<n;i++){
        if(a[i]==b[0]){
            index = i;
            break;
        }
    }


    for(int i=0;i<n;i++){
        if(a[index%n]!=b[i]){
            poss = false;
            break;
        }
        index++;
    }

    if(index==0){
        if(k!=0){
            if(n==2){
                if(k%2) poss = false;
            }else{
                if(k==1) poss = false;
            }
        }
    }else{
        if(k==0)poss = false;
        else{
            if(n==2){
                if(k%2==0) poss = false;
            }
        }
    }


    // cout<<"Case #"<<c<<": ";
    if(poss) cout<<"Case #"<<c<<": "<<"YES"<<endl;
    else{
        cout<<"Case #"<<c<<": "<<"NO"<<endl;
    }

    return;
}

signed main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;cin >> t;
    for(int i=0;i<t;i++){
        testcase(i+1);
    }
}