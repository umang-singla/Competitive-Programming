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
    int n,m,k;
    cin>>n>>m>>k;

    string a,b;
    cin>>a>>b;

    string c="";

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int max_op=0;
    int pos=0;
    int i=0,j=0;
    while(i<n&&j<m){
        if(max_op==k){
            if(pos==0){
                c += b[j];
                j++;
                pos =1;
            }else{
                c += a[i];
                i++;
                pos = 0;
            }
            max_op = 1;
        }
        else{
            if(a[i]<b[j]){
                c += a[i];
                i++;
                if(pos==1){
                    max_op=1;
                    pos=0;
                }
                else max_op++;
            }else{
                c += b[j];
                j++;
                if(pos==0){
                    max_op=1;
                    pos = 1;
                }
                else max_op++;
            }
        }
    }

    cout<<c<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}