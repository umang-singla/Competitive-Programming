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

bool isfactor(string a, string b)
{
    int l_a = a.length(), l_b = b.length();
    bool ans = true;
    for (int i = 0; i < l_a; i++)
    {
        if (a[i] != b[i % l_b])
        {
            ans = false;
            break;
        }
    }
    return ans;
}

void testcase()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;

    int hcf = __gcd((int)s1.length(), (int)s2.length());

    set<int> factors;
    for (int i = 1; i <= sqrt(hcf); i++)
    {
        if (hcf % i == 0)
        {
            factors.insert(i);
            factors.insert(hcf / i);
        }
    }

    int ans = 0;

    for (auto l : factors)
    {

        string temp = s1.substr(0, l);
        if (isfactor(s1, temp) && isfactor(s2, temp))
        {
            ans++;
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}