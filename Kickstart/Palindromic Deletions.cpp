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
#define vvi vector << vi >>
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

bool isPalindrome(string s)
{
    int n = s.size();
    FOR(i, 0, n)
    {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}

int candie(string s, int n)
{
    if (n == 1)
        return 1;
    else
    {
        int ans = 0;
        FOR(i, 0, n)
        {
            string temp = s.substr(0, i);
            temp += s.substr(i + 1, n - i - 1);
            if (isPalindrome(temp))
                ans = (ans + (n-1))%mod;
            ans = (ans + candie(s, n - 1))%mod;
        }
        // cout<<ans<<" ";

        return ans;
    }
}

int power(int a,int n){
    int ans=1;
    int fact = a;
    while(n){
        if(n%2){
            ans  = (ans*fact)%mod;
        }
        n/=2;
        fact = (fact*fact)%mod;
    }
    return ans;
}



signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i=0;i<t;i++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int ans = 0;

        ans = candie(s, n);


        // cout << ans << endl;
        ans = ans%mod;

        int fact=1;
        FOR(i,2,n+1){
            fact = (fact*i)%mod;
        }

        cout<<"Case #"<<i+1<<": "<<(ans*power(fact,mod-2))%mod<<endl;

    }
}