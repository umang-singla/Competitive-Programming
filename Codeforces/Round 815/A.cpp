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

int lcm(int a,int b){
    int temp = a*b;
    temp /= __gcd(a,b);
    return temp;
}

void testcase()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int temp = __gcd(a,b);
    a /= temp;
    b /= temp;
    temp = __gcd(c,d);
    c /= temp;
    d /= temp;

    // cout<<a<<" "<<b<<endl;

    if(a==c&&b==d) cout<<0<<endl;
    else if(a!=0&&c!=0){
        if((a*d)%(b*c) == 0 || (b*c)%(a*d) == 0) cout<<1<<endl;
        else if(a==c){
            if(b%d==0||d%b==0) cout<<1<<endl;
            else cout<<2<<endl;
        }else if(b==d){
            if(a%c==0||c%a==0) cout<<1<<endl;
            else cout<<2<<endl;
        }else{
            cout<<2<<endl;
        }
    }
    else if(a==0 && c !=0) cout<<1<<endl;
    else if(c==0 && a !=0) cout<<1<<endl;
    else cout<<0<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}