#include<bits/stdc++.h>
using namespace std;
bool vis[20][20];
int dis[20][20];
vector<pair<int,int>>D={{0, 1}, {0,-1}, {-1,0}, {1,0}};
int N,M;
char A[20][20];
bool valid(int i,int j)
{
    if(i<0 || i>=N || j<0 || j>=M)
        return false;
    return true;
}
void bfs(int si,int sj)
{
    queue<pair<int,int>>Q;
    Q.push({si,sj});
    vis[si][sj]=true;
    dis[si][sj]=0;
    while(!Q.empty())
    {
        pair<int,int>par=Q.front();
        int A=par.first, B=par.second;
        Q.pop();
        for(int i=0; i<4; i++)
        {
            int ci=A+D[i].first;
            int cj=B+D[i].second;
            if(valid(ci,cj)==true && vis[ci][cj]==false)
            {
                Q.push({ci,cj});
                vis[ci][cj]=true;
                dis[ci][cj]=dis[A][B]+1;
            }
        }
    }
}
int main()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>A[i][j];
        }
    }
    int si,sj;
    cin>>si>>sj;
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    bfs(si,sj);
    cout<<dis[2][3];
    return 0;
}
