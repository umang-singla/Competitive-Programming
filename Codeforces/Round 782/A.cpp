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
        int n, r, b;
        cin >> n >> r >> b;

        int min_r = r / (b + 1);
        int extra_r = r%(b + 1);

        for (int i = 0; i < extra_r; i++)
        {
            for (int j = 0; j < min_r + 1; j++)
            {
                cout << "R";
            }
            cout << "B";
        }
        for (int i = 0; i < b - extra_r; i++)
        {
            for (int i = 0; i < min_r; i++)
            {
                cout << "R";
            }
            cout << "B";
        }
        for(int i=0; i < r - (b-extra_r)*min_r - extra_r*(min_r + 1); i++)
        {
            cout << "R";
        }
        cout<<endl;
    }
    return 0;
}