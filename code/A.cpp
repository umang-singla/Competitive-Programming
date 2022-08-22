#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>>adj;
vector<vector<bool>>vis;
int n,m;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
map<int,vector<pair<int,int>>> mat;
map<int,vector<int>> seive;
bool check(int a,int b)
{
    if(a<0||a>n-1||b<0||b>m-1)
    return false;
    return true;
}
int bfs(int x1,int y1,int x2 ,int y2)
{
    vector<vector<int>>d(n,vector<int>(m,-1));
    d[x1][y1]=0;
    if(x1==x2&&y1==y2)
    return d[x1][y1];
    queue<pair<int,int>>q;
   q.push({x1,y1});
   vis[x1][y1]=true;
   while(!q.empty())
   {
     int a=q.front().first;
     int b=q.front().second;
     q.pop();
    for(auto i:seive[adj[a][b]]){
        if(mat.find(i)!=mat.end()){
            for(auto to:mat[i]){
                if(!vis[to.first][to.second]){
                    d[to.first][to.second] = d[a][b] + 1;
                    vis[to.first][to.second]=1;
                    q.push(to);
                }
            }
        }
    }
     for(int i=0;i<4;i++)
     {
         if(check(a+dx[i],b+dy[i])&&!vis[a+dx[i]][b+dy[i]])
         {
            vis[a+dx[i]][b+dy[i]]=true;
            d[a+dx[i]][b+dy[i]]=d[a][b]+1;
            q.push({a+dx[i],b+dy[i]});
         }
     }
   }
   return d[x2][y2];
}
int32_t main() 
{
    cin>>n>>m;
    // mat.clear();
    adj=vector<vector<int>>(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>adj[i][j];
            mat[adj[i][j]].push_back({i,j});
        }
    }

    for(int i=1;i<=100010;i++){
        for(int j=1;j*i<=100010;j++){
            seive[i*j].push_back(i);
        }
    }


    int q;
    cin>>q;
    while(q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1--,y1--,x2--,y2--;
        vis=vector<vector<bool>>(n,vector<bool>(m,false));
        int s=bfs(x1,y1,x2,y2);
        if(s!=-1)
        {
            if(s<=4)
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
        else
        cout<<"NO"<<endl;
    }
    return 0;
}