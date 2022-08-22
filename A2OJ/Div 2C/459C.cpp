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

#define endl "\n"

using namespace std;

void testcase()
{

    int n, k, d;
    cin >> n >> k >> d;

    if (k >= n)
    {

        FOR(i, 0, d)
        {
            FOR(j, 0, n)
            {
                cout << j + 1 << " ";
            }
            cout << endl;
        }
    }
    else
    {

        if (n == 1)
        {
            FOR(i, 0, d)
            {
                cout << 1 << endl;
            }
            cout << endl;
        }
        else if (d == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            if (k == 1)
                cout << -1 << endl;
            else
            {
                int min_d = 0;
                int temp = n;
                while (temp>1)
                {
                    min_d++;
                    temp = temp / k + (temp % k > 0 && temp / k > 0);
                }
                if (d < min_d)
                {
                    cout << -1 << endl;
                }
                else
                {
                    int ans[d][n];
                    temp = n;
                    int temp_d = 0,index=0;
                    while (temp>1)
                    {
                        temp = temp / k + (temp % k >0);
                        // cout<<temp<<endl;
                        int i = 0, j = -1,t=0;
                        while (i < n)
                        {
                            if(index > 0 && i>0 && ans[index-1][i]!=ans[index-1][i-1]){
                                j = -1;
                                t=0;
                            }
                            if(t%temp==0) j = (j+1)%k;
                            ans[index][i] = j+1;
                            cout<<j+1<<" ";
                            t++;
                            i++;
                        }
                        index++;
                        temp_d++;
                        cout << endl;
                    }
                    // cout<<'b';
                    if(temp_d < d){
                        FOR(i, 0, d - temp_d)
                        {
                            FOR(j, 0, n)
                            {
                                cout << 1 << " ";
                            }
                            cout << endl;
                        }
                    }
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