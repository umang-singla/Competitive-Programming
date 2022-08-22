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

bool comparator(const pii &a,const pii &b) {
    if(abs(a.ff) < abs(b.ff)) return true;
    else if(abs(a.ff) == abs(b.ff)) return abs(a.ss) < abs(b.ss);
    else return false;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector <pii> v;
    int cnt = 0;
    FOR(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        v.pb(mp(x, y));
        if(x ==0 || y == 0) cnt += 4;
        else cnt += 6;
    }

    sort(all(v),comparator);

    cout<<cnt<<endl;

    vector<string> ans;

    FOR(i,0,n){
        if(v[i].ff==0){
            if(v[i].ss > 0){
                cout<<"1 "+to_string(v[i].ss)+" U"<<"\n";
                cout<<2<<"\n";
                cout<<"1 "+to_string(v[i].ss)+" D"<<"\n";
                cout<<3<<"\n";
            }else{
                cout<<"1 "+to_string(-1*v[i].ss)+" D"<<"\n";
                cout<<2<<"\n";
                cout<<"1 "+to_string(-1*v[i].ss)+" U"<<"\n";
                cout<<3<<"\n";
            }
        }else if(v[i].ff > 0){
            if(v[i].ss > 0){
                cout<<"1 "+to_string(v[i].ss)+" U"<<"\n";
                cout<<"1 "+to_string(v[i].ff)+" R"<<"\n";
                cout<<2<<"\n";
                cout<<"1 "+to_string(v[i].ff)+" L"<<"\n";
                cout<<"1 "+to_string(v[i].ss)+" D"<<"\n";
                cout<<3<<"\n";
            }else if(v[i].ss < 0){
                cout<<"1 "+to_string(-1*v[i].ss)+" D"<<"\n";
                cout<<"1 "+to_string(v[i].ff)+" R"<<"\n";
                cout<<2<<"\n";
                cout<<"1 "+to_string(v[i].ff)+" L"<<"\n";
                cout<<"1 "+to_string(-1*v[i].ss)+" U"<<"\n";
                cout<<3<<"\n";
            }else{
                cout<<"1 "+to_string(v[i].ff)+" R"<<"\n";
                cout<<2<<"\n";
                cout<<"1 "+to_string(v[i].ff)+" L"<<"\n";
                cout<<3<<"\n";
            }
        }else{
            if(v[i].ss > 0){
                cout<<"1 "+to_string(v[i].ss)+" U"<<"\n";
                cout<<"1 "+to_string(-1*v[i].ff)+" L"<<"\n";
                cout<<2<<"\n";
                cout<<"1 "+to_string(-1*v[i].ff)+" R"<<"\n";
                cout<<"1 "+to_string(v[i].ss)+" D"<<"\n";
                cout<<3<<"\n";
            }else if(v[i].ss < 0){
                cout<<"1 "+to_string(-1*v[i].ss)+" D"<<"\n";
                cout<<"1 "+to_string(-1*v[i].ff)+" L"<<"\n";
                cout<<2<<"\n";
                cout<<"1 "+to_string(-1*v[i].ff)+" R"<<"\n";
                cout<<"1 "+to_string(-1*v[i].ss)+" U"<<"\n";
                cout<<3<<"\n";
            }else{
                cout<<"1 "+to_string(-1*v[i].ff)+" L"<<"\n";
                cout<<2<<"\n";
                cout<<"1 "+to_string(-1*v[i].ff)+" R"<<"\n";
                cout<<3<<"\n";
            }
        }
    }    
}