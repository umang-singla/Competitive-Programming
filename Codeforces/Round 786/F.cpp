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
    int n, m, q;
    cin >> n >> m >> q;

    string a[n];

    int cnt_str = 0;
    FOR(i, 0, n)
    {
        cin >> a[i];
    }

    int moves = 0;

    FOR(i, 0, n)
    {
        FOR(j, 0, m)
        {
            if (a[i][j] == '*')
            {
                cnt_str++;
            }
        }
    }

    pii p;
    p.ff = cnt_str / n;
    p.ss = cnt_str % n;

    FOR(i, 0, n)
    {
        FOR(j, 0, m)
        {
            if (a[i][j] == '*')
            {
                int temp = n * (j) + i + 1;
                if (temp > cnt_str)
                {
                    moves++;
                }
            }
        }
    }

    // cout << moves;

    while (q--)
    {

        int x, y;
        cin >> x >> y;

        if (a[x - 1][y - 1] == '.')
        {
            cnt_str++;
            int y1 = (cnt_str) / n - 1 + ((cnt_str) % n > 0),x1=(cnt_str) % n-1;
            if(x1 <0 ) x1 = n-1;
            // cout<<x1<<"v";
            if(x1>=0&&y1>=0&&a[x1][y1]=='*'){
                if(n*(y-1)+x > cnt_str){
                    cout<<moves<<endl;
                }else{
                    moves--;
                    cout<<moves<<endl;
                }
            }else{
                if(n*(y-1)+x > cnt_str){
                    moves++;
                    cout<<moves<<endl;
                }else{
                    cout<<moves<<endl;
                }
            }
            a[x-1][y-1] = '*';
        }
        else
        {
            cnt_str--;
            // cout<<cnt_str<<" ";
            int x1=((cnt_str+1))%n-1,y1=(cnt_str+1)/n - 1 + ((cnt_str+1)%n > 0);
            if(x1<0) x1 = n-1;
            if (x1>=0&&y1>=0&&a[x1][y1] == '*')
            {

                if (n * (y - 1) + x > cnt_str)
                {
                    cout<<moves<<endl;
                }else{
                    moves++;
                    // cout<<'a';
                    cout<<moves<<endl;
                }
            }else{
                if (n * (y - 1) + x > cnt_str)
                {
                    moves--;
                    cout<<moves<<endl;
                }else{
                    cout<<moves<<endl;
                }
            }
            a[x-1][y-1] = '.';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}