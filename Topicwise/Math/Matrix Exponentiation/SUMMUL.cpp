// https://www.spoj.com/problems/SUMMUL/
#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define int long long int

int **Matrix_k(int **F, int **F1, int d)
{
    int **temp;

    temp = new int *[d];
    for (int i = 0; i < d; i++)
    {
        temp[i] = new int[d];
    }

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            temp[i][j] = 0;
            for (int k = 0; k < d; k++)
            {
                temp[i][j] += F[i][k] * F1[k][j];
            }
        }
    }

    return temp;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int f1 = 0, f2 = 1;

        int **F, **F1;

        F = new int *[4];
        F1 = new int *[4];

        for (int i = 0; i < 4; i++)
        {
            F[i] = new int[4];
            F1[i] = new int[4];
        }

        F[0][0] = 3,F[0][1] = -1,F[0][2] = 1,F[0][3] = 0;
        F[1][0] = 1,F[1][1] = 0,F[1][2] = 0,F[1][3] = 0;
        F[2][0] = 0,F[2][1] = 0,F[2][2] = 1,F[2][3] = 1;
        F[3][0] = 0,F[3][1] = 0,F[3][2] = 0,F[3][3] = 1;

        F1[0][0] = 1,F1[0][1] = 0,F1[0][2] = 0,F1[0][3] = 0;
        F1[1][0] = 0,F1[1][1] = 1,F1[1][2] = 0,F1[1][3] = 0;
        F1[2][0] = 0,F1[2][1] = 0,F1[2][2] = 1,F1[2][3] = 0;
        F1[3][0] = 0,F1[3][1] = 0,F1[3][2] = 0,F1[3][3] = 1;

        

        int temp = n-2;
        while(temp>0){
            if(temp%2){
                F1 = Matrix_k(F,F1,4);
            }
            temp/=2;
            F = Matrix_k(F,F,4);
        }

        int ans = F1[0][0] * f2 + F1[0][1] * f1 + F1[0][2]*2 + F1[0][3];
        if(n==1) cout<<0<<endl;
        else if(n==2) cout<<1<<endl;
        else cout << ans << endl;
    }
}