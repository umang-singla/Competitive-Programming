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
    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    int n,m;
    cin>>n>>m;

    string a[n];
    FOR(i,0,n) cin>>a[i];

    int **cnt = new int*[n];
    FOR(i,0,n){
        cnt[i] = new int[26];
    }

    FOR(i,0,n){
        FOR(j,0,26) cnt[i][j]=0;
    }
    // memset(cnt,0,sizeof(cnt));
    FOR(i,0,n){
        for(auto c:a[i]){
            cnt[i][(int)(c-'a')]++;
        }
    }

    int **prefix = new int*[26];;
    FOR(i,0,26){
        prefix[i] = new int[n+1];
    }

    FOR(i,0,26){
        FOR(j,0,n+1) prefix[i][j] = 0;
    }

    // memset(prefix,0,sizeof(prefix));

    FOR(i,0,26){
        FOR(j,0,n){
            prefix[i][j+1] = prefix[i][j] + cnt[j][i];
        }
    }

    // cout<<'a';

    while (m--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        int count=0,i=0;
        while (i<26&&count<k)
        {
            count += (prefix[i][r]-prefix[i][l-1]);
            i++;
        }
        // cout<<'a';

        i--;
        cout<<(char)(i+'a')<<endl;   
        
    }
}