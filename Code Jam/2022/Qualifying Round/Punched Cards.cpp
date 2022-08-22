#include <bits/stdc++.h>
#define mod 1000000007
#define int long long int

using namespace std;

signed main()
{
    int t;
    cin >> t;
    for (int p = 0; p < t; p++)
    {
        cout<<"Case #"<<p+1<<":\n";
        int r, c;
        cin >> r >> c;
        cout << "..";
        for (int i = 0; i < c - 1; i++)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        cout << "..";
        for (int i = 0; i < c - 1; i++)
        {
            cout << "|.";
        }
        cout << "|" << endl;
        for (int i = 0; i < r - 1; i++)
        {
            cout << "+-";
            for (int i = 0; i < c - 1; i++)
            {
                cout << "+-";
            }
            cout << "+" << endl;
            cout << "|.";
            for (int i = 0; i < c - 1; i++)
            {
                cout << "|.";
            }
            cout << "|" << endl;
        }
        cout << "+-";
        for (int i = 0; i < c - 1; i++)
        {
            cout << "+-";
        }
        cout << "+" << endl;
    }

    return 0;
}