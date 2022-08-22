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
#define mod 1000000007

using namespace std;

bool ispalindrome(int n){
    string s = "";
    while(n){
        s += (n%10 + '0');
        n /= 10;
    }

    return s == string(s.rbegin(), s.rend());
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    vector<int> palindrome;

    for(int i=1;i<40001;i++){
        if(ispalindrome(i)){
            // cout<<i<<" ";
            palindrome.pb(i);
        }
    }

    int n = 40001;

    int dp[n+1]={0};

    dp[0] = 1;
    
    for(int i=0;i<palindrome.size();i++){
        for(int j=1;j<=n;j++){
            if(j>=palindrome[i]){
                dp[j] = (dp[j] + dp[j-palindrome[i]])%mod;
            }
        }
    }   


    while (t--)
    {
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
}