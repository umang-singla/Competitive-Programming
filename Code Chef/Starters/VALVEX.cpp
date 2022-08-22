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
    int a[n];
    vector<int> odd, even;
    FOR(i, 0, n)
    {
        cin >> a[i];
        if (a[i] % 2)
        {
            odd.pb(a[i]);
        }
        else
        {
            even.pb(a[i]);
        }
    }

    if (odd.size() == 0)
    {
        sort(all(even));
        cout << even[even.size() - 1] << endl;
    }
    else if (even.size() == 0)
    {
        sort(all(odd));
        cout << odd[odd.size() - 1] << endl;
    }
    else
    {
        sort(odd.rbegin(), odd.rend());
        sort(even.rbegin(), even.rend());
        int a = 0, b = 0;
        int a3 = 0, b3 = 0;

        int i = 0, j = 0;
        int p1, p2, prev1, prev2;
        p1 = prev1 = 0;
        p2 = prev2 = 1;

        while (true)
        {
            prev1 = p1;
            prev2 = p2;

            if (p1)
            {
                if (i < even.size())
                {
                    a += even[i];
                    p1 = 1 - p1;
                    i++;
                }
            }
            else
            {
                if (j < odd.size())
                {
                    a += odd[j];
                    p1 = 1 - p1;
                    j++;
                }
            }
            if (p2)
            {
                if (i < even.size())
                {
                    b += even[i];
                    p2 = 1 - p2;
                    i++;
                }
            }
            else
            {
                if (j < odd.size())
                {
                    b += odd[j];
                    p2 = 1 - p2;
                    j++;
                }
            }

            if (prev1 == p1 && prev2 == p2)
            {
                break;
            }
            // cout << i << " " << j << endl;
        }

        p1 = prev1 = 1;
        p2 = prev2 = 0;
        i=0,j=0;

        while (true)
        {
            prev1 = p1;
            prev2 = p2;

            if (p1)
            {
                if (i < even.size())
                {
                    a3 += even[i];
                    p1 = 1 - p1;
                    i++;
                }
            }
            else
            {
                if (j < odd.size())
                {
                    a3 += odd[j];
                    p1 = 1 - p1;
                    j++;
                }
            }
            if (p2)
            {
                if (i < even.size())
                {
                    b3 += even[i];
                    p2 = 1 - p2;
                    i++;
                }
            }
            else
            {
                if (j < odd.size())
                {
                    b3 += odd[j];
                    p2 = 1 - p2;
                    j++;
                }
            }

            if (prev1 == p1 && prev2 == p2)
            {
                break;
            }
            // cout << i << " " << j << endl;
        }

        int ans = max(a, b);
        int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
        if (odd.size() >= 2)
        {
            i = 0, j = 0;
            p1 = prev1 = 0;
            p2 = prev2 = 0;
            while (true)
            {
                prev1 = p1;
                prev2 = p2;

                if (p1)
                {
                    if (i < even.size())
                    {
                        a1 += even[i];
                        p1 = 1 - p1;
                        i++;
                    }
                }
                else
                {
                    if (j < odd.size())
                    {
                        a1 += odd[j];
                        p1 = 1 - p1;
                        j++;
                    }
                }
                if (p2)
                {
                    if (i < even.size())
                    {
                        b1 += even[i];
                        p2 = 1 - p2;
                        i++;
                    }
                }
                else
                {
                    if (j < odd.size())
                    {
                        b1 += odd[j];
                        p2 = 1 - p2;
                        j++;
                    }
                }

                if (prev1 == p1 && prev2 == p2)
                {
                    break;
                }
                // cout << i << " " << j << endl;
            }
        }
        if (even.size() >= 2)
        {
            i = 0, j = 0;
            p1 = prev1 = 1;
            p2 = prev2 = 1;
            while (true)
            {
                prev1 = p1;
                prev2 = p2;

                if (p1)
                {
                    if (i < even.size())
                    {
                        a2 += even[i];
                        p1 = 1 - p1;
                        i++;
                    }
                }
                else
                {
                    if (j < odd.size())
                    {
                        a2 += odd[j];
                        p1 = 1 - p1;
                        j++;
                    }
                }
                if (p2)
                {
                    if (i < even.size())
                    {
                        b2 += even[i];
                        p2 = 1 - p2;
                        i++;
                    }
                }
                else
                {
                    if (j < odd.size())
                    {
                        b2 += odd[j];
                        p2 = 1 - p2;
                        j++;
                    }
                }

                if (prev1 == p1 && prev2 == p2)
                {
                    break;
                }
                // cout << i << " " << j << endl;
            }
        }

        // cout<<a<<" "<<b<<" "<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<" "<<a3<<" "<<b3<<endl;

        int ans1,ans2;

        if(b == b1){
            ans1 = max(a1,a);
        }
        else{
            if(b>b1){
                ans1 = a;
            }
            else{
                ans1 = a1;
            }
        }

        if(b2 == b3){
            ans2 = max(a2,a3);
        }
        else{
            if(b3>b2){
                ans2 = a3;
            }
            else{
                ans2 = a2;
            }
        }

        cout << max(ans1,ans2) << endl;
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
    {
        testcase();
    }
}