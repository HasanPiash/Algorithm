#include<bits/stdc++.h>
using namespace std;
char A[20][20];
bool vis[20][20];
vector<pair<int,int>>D={{0,1},{0,-1},{-1,0},{1,0}};
int N,M;
bool valid(int i, int j)
{
    if(i<0 || i>=N || j<0 || j>=M)
        return false;
    return true;
}
void dfs(int si,int sj)
{
    cout<<si<<" "<<sj<<endl;
    vis[si][sj]=true;
    for(int i=0; i<4; i++)
    {
        int ci=si+D[i].first;
        int cj=sj+D[i].second;
        if (valid(ci,cj)==true && vis[ci][cj]==false)
        {
            dfs(ci,cj);
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
    dfs(si,sj);
    return 0;
}
