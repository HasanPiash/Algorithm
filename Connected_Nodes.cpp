#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,E;
    cin>>N>>E;
    vector<vector<int>>adj(N);
    vector<pair<int,int>>v;
    while(E--){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int Q;
    cin>>Q;
    while(Q--){
        int X;
        cin>>X;
        if(adj[X].empty()){
            cout<<"-1\n";
        }
        else{
            sort(adj[X].begin(),adj[X].end(),greater<int>());
            for(int node:adj[X]){
                cout<<node<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}