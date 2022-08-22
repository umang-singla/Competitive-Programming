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
    int l,r;
    cin>>l>>r;

    int power=1;
    while(power<l) power*=2;

    int a,b,c,d;
    a=l,b=l+1,c=l+2,d=l+3;

    bool poss=false;

    for(int i=0;i<100;i++){

        if(d>r) break;

        if((a^b^c^d) == 0){
            poss=true;
            break;
        }

        a++;
        b++;
        c++;
        d++;
    }

    if(poss) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    else cout<<-1<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}