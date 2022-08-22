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

using namespace std;

void testcase()
{

    int n;
    cin>>n;
    int a[n];

    FOR(i, 0, n)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    set<int> s;

    FOR(i, 1, n)
    {
        s.insert(a[i] - a[i - 1]);
    }
    if (n == 1)
    {
        cout << "-1" << endl;
        return;
    }

    if (s.size() > 2)
    {
        cout << 0 << endl;
    }
    else
    {
        if (s.size() == 1)
        {
            int x = *s.begin();
            if (x == 0)
            {
                cout << 1 << endl;
                cout << a[0];
            }
            else
            {
                if (n == 2)
                {
                    if (x % 2 == 0)
                    {
                        cout << 3 << endl;
                        cout << a[0] - x << " " << (a[0] + a[1]) / 2 << " " << a[1] + x;
                        return;
                    }
                }
                cout << 2 << endl;
                cout << a[0] - x << " " << a[n - 1] + x << endl;
            }
        }
        else
        {
            int x1 = *s.begin();
            int x2 = *(++s.begin());
            int cnt = 0,index;
            FOR(i, 1, n)
            {
                if (a[i] - a[i-1] == x2)
                {
                    cnt++;
                    index = i;
                }
            }
            if(cnt>1){
                cout<<0<<endl;
            }else{
                if(x1*2 == x2){
                    cout<<1<<endl;
                    cout<<(a[index-1]+a[index])/2<<endl;
                }else{
                    cout<<0<<endl;
                }
            }
        }
    }
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