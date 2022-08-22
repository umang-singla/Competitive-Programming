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

bool ispalindrome(string &a){
    string b = a;
    reverse(b.begin(),b.end());

    return b==a;
}

void testcase()
{
    string s;
    int x;
    cin>>s>>x;

    set <string> temp;
    int ans=0;
    int hr = 10*(s[0]-'0')+s[1]-'0';
    int mi = 10*(s[3]-'0') + s[4] - '0';
    temp.insert(s);

    for(int i=0;i<1440;i++){
        hr += x/60;
        mi += x%60;

        if(mi>=60){
            hr++;
            mi%=60;
        }
        if(hr>=24){
            hr%=24;
        }

        string a="";

        if(hr<10) a += '0';
        a += to_string(hr);
        a+=':';
        if(mi<10) a+='0';
        a += to_string(mi);
        temp.insert(a);
    }

    for(auto i:temp){
        if(ispalindrome(i)) ans++;
    }

    cout<<ans<<endl;


}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}