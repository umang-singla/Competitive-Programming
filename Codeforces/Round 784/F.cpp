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
#define FOR(i, l, r) for (i = l; i < r; ++i)
#define FORr(i, l, r) for (i = l; i >= r; --i)

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
    int w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    int prefix[n],suffix[n];

    prefix[0]=w[0];

    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+w[i];
    }

    suffix[n-1]=w[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]+w[i];
    }


    int i=0,j=n-1,sum = 0;

    while(i<j){
        if(prefix[i]==suffix[j]){
            sum = i + 1 + n - j;
            i++;
            j--;
        }else if(prefix[i]<suffix[j]){
            i++;
        }else{
            j--;
        }
    }

    cout<<sum<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        testcase();
    }
}
