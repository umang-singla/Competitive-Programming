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

using namespace std;

void testcase()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    char ans[n];

    if(s == "9"){
        cout<<"2"<<endl;
        return;
    }

    if (s[0] < s[n - 1])
    {
        for (int i = 0; i < n / 2; i++)
        {
            // cout<<i<<endl;
            if (s[i] < s[n - 1 - i])
            {
                ans[i] = ('0' + s[n - 1 - i] - s[i]);
                ans[n - 1 - i] = '0';
            }
            else
            {
                ans[i] = '0';
                ans[n - 1 - i] = ('0' + s[i] - s[n - 1 - i]);
            }
        }
        if (n % 2)
            ans[n / 2] = '0';

        for (int i = 0; i < n; i++)
        {
            cout << ans[i];
        }
        cout << endl;
    }
    else
    {
        if (s[0] != '9')
        {
            s[0]++;
            ans[0] = '1';
            ans[n - 1] = ('0' + s[0] - s[n-1]);
            for (int i = 1; i < n / 2; i++)
            {
                if (s[i] < s[n - 1 - i])
                {
                    ans[i] = ('0' + s[n - 1 - i] - s[i]);
                    ans[n - 1 - i] = '0';
                }
                else
                {
                    ans[i] = '0';
                    ans[n - 1 - i] = ('0' + s[i] - s[n - 1 - i]);
                }
            }

            if (n % 2)
                ans[n / 2] = '0';

            for (int i = 0; i < n; i++)
            {
                cout << ans[i];
            }
            cout << endl;
        }else{
            for(int i=0;i<n;i++) ans[i]= ('9' - s[i]) + '0';

            string temp="";
            FOR(i,0,n-1) temp+='1';
            temp+='2';

            int carry = 0;

            for(int i=n-1;i>=0;i--){
                int k = ans[i]-'0' + temp[i]-'0'+carry;
                ans[i]= (ans[i]-'0' + temp[i]-'0'+carry)%10 + '0';
                carry = k/10;
            }

            for (int i = 0; i < n; i++)
            {
                cout << ans[i];
            }
            cout << endl;



        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        testcase();
}