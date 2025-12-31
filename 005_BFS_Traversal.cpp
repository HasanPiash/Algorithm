#include<bits/stdc++.h> 
using namespace std;
vector<int>V[1005];
bool vis[1005];
void bfs(int src)
{
    queue<int>Q;
    Q.push(src);
    vis[src]=true;
    while(!Q.empty())
    {
        int par=Q.front();
        Q.pop();
        cout<<par<<endl;
        for(int child:V[par])
        {
            if(vis[child]==false)
            {
                Q.push(child);
                vis[child] = true;
            }
        }
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
    int src;
    cin >> src;
    memset(vis, false, sizeof(vis));
    bfs(src);
    return 0;
}
