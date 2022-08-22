#include <bits/stdc++.h>
#define mod 1000000007
#define int long long int

using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            v.push_back({a[i], i});
        }
        sort(v.begin(), v.end());
        string s;
        cin >> s;

        bool same = true;
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                same = false;
                break;
            }
        }

        bool sorted = true;
        for (int i = 0; i < n; i++)
        {
            if (i != v[i].second)
            {
                sorted = false;
                break;
            }
        }

        if (same)
        {

            if (!sorted)
            {
                cout << "-1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else
        {
            int min_s = -1, min_n = -1, max_n = -1, max_s = -1;
            int low = 0, high = n - 1;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'N')
                {
                    min_n = i;
                    break;
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'S')
                {
                    min_s = i;
                    break;
                }
            }
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == 'N')
                {
                    max_n = i;
                    break;
                }
            }
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == 'S')
                {
                    max_s = i;
                    break;
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (v[i].second != i)
                {
                    low = i;
                    break;
                }
            }
            for (int i = n - 1; i >= 0; i--)
            {
                if (v[i].second != i)
                {
                    high = i;
                    break;
                }
            }
            if(sorted) cout<<"0\n";
            else{
                if((min_s<=low&&max_n>=high && min_s != -1 && max_n != -1)||(min_n<=low&&max_s>=high&&min_n!=-1&&max_s!=-1)) cout<<"1\n";
                else cout<<2<<"\n";
            }
        }
    }

    return 0;
}