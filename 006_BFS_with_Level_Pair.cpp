#include <bits/stdc++.h>
using namespace std;
vector<int>V[1005];
bool vis[1005]; 
void bfs(int src,int des)
{
    queue<pair<int,int>>Q;
    Q.push({src,0});
    vis[src]=true;
    bool paisi=false;
    while(!Q.empty())
    {
        pair<int,int>P=Q.front();
        Q.pop();
        int par=P.first;
        int level=P.second;
        if(par==des)
        {
            cout<<level<<endl;
            paisi=true;
        }
        for(int child:V[par])
        {
            if(vis[child]==false)
            {
                Q.push({child,level+1});
                vis[child]=true;
            }
        }
    }
    if(paisi==false)
    {
        cout<<-1<<endl;
    }
}
int main()
{
    int N,E;
    cin>>N>>E;
    while(E--)
    {
        int A,B;
        cin>>A>>B;
        V[A].push_back(B);
        V[B].push_back(A);
    }
    int src;
    cin>>src;
    memset(vis,false,sizeof(vis));
    bfs(src,9);
    return 0;
}
