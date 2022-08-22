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

    string s;
    cin >> s;
    int a, b;
    cin >> a >> b;

    int r = 0;

    int ad[s.size()], bd[s.size()];
    for(int i=0;i<s.size();i++){
        r = 10*r + (s[i]-'0');
        r=r%a;
        // cout<<r<<" ";
        if(r!=0) ad[i] = 0;
        else ad[i] = 1;
    }
    r=0;
    int power = 1;

    for(int i=s.size()-1;i>=0;i--){
        power%=b;
        r = r + power*(s[i]-'0');
        power = power*10;
        r= r%b;
        if(r!=0) bd[i] = 0;
        else bd[i] = 1;
    }

    for(int i=0;i<s.size()-1;i++){
        if(ad[i] && bd[i+1] && s[i+1] != '0'){
            cout<<"YES"<<endl;
            cout<<s.substr(0,i+1)<<endl;
            cout<<s.substr(i+1,s.size()-i-1)<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin>>t;
    while (t--)
    {
        testcase();
    }
}