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
    int a[3];
    cin>>a[0]>>a[1]>>a[2];

    sort(a,a+3);
    for(int i=0;i<32;i++){
        // cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
        int bit1=a[0]%2,bit2=a[1]%2,bit3=a[2]%2;

        if((bit1+bit2+bit3)%3==0)break;
        else{
            if(bit1+bit2+bit3==1){
                if(bit1==1){
                    // cout<<'a';
                    a[0] += (1);
                }else if(bit2==1){
                    a[1] += (1);
                }else{
                    a[2] += (1);
                }
            }else{
                if(bit1==0){
                    a[0] += (1);
                }else if(bit2==0){
                    // cout<<'a';
                    a[1] += (1);
                }else{
                    a[2] += (1);
                }
            }
            a[0]/=2;
            a[1]/=2;
            a[2]/=2;
        }
    }

    if(a[0]==a[1]&&a[1]==a[2]) cout<<"YES"<<endl;
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