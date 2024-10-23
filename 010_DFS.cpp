#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>V[N];
bool vis[N];
void dfs(int src)
{
    cout<<src<<endl;
    vis[src]=true;
    for(int child:V[src])
    {
        if(vis[child]==false)
            dfs(child);
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
        v[A].push_back(B);
        v[B].push_back(A);
    }
    memset(vis,false,sizeof(vis));
    dfs(0);
    return 0;
}
