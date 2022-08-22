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
    int n, k;
    cin >> n >> k;
    int a[n];
    FOR(i, 0, n)
        cin >> a[i];

    int prefix[n + 1];
    prefix[0] = 0;
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + a[i];
    }

    if (k < n)
    {
        int sum = 0;

        for (int i = k - 1; i < n; i++)
        {
            sum = max(sum, prefix[i + 1] - prefix[i + 1 - k]);
        }
        sum += (k * (k - 1)) / 2;
        cout << sum << endl;
    }
    else
    {
        int sum = prefix[n];
        n--;
        if(n==0){
            sum+=k-1;
        }else if(k%n){
            int mod = k%n;
            sum += (mod*(mod-1))/2;
            // cout<<sum<<endl;
            int i=1,temp=2;
            for(;i<=mod-1;i++) {
                sum+=temp;
                temp+=2;
            }
            temp--;
            while(i<n+1){
                sum+=temp;
                temp++;
                i++;
            }
            k-= (mod+n);
            // cout<<sum<<endl;
            sum += (k/n)*(n*(n+1));
        }else{
            int mod = n;
            sum += (mod*(mod-1))/2;
            // cout<<sum<<endl;
            int i=1,temp=2;
            for(;i<=mod-1;i++) {
                sum+=temp;
                temp+=2;
            }
            temp--;
            while(i<n+1){
                sum+=temp;
                temp++;
                i++;
            }
            k-= (mod+n);
            // cout<<sum<<endl;
            sum += (k/n)*(n*(n+1));
        }

        cout<<sum<<endl;


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