#include<bits/stdc++.h>
using namespace std;
bool vst[1000][1000];
vector<pair<int,int>>d={{0,1},{0,-1},{-1,0},{1,0}};
int N,M;
char A[1000][1000];

bool valid(int i,int j){
    if(i<0 || i>=N || j<0 || j>=M)return false;
    if(A[i][j]=='#' || vst[i][j])return false;
    return true;
}

bool bfs(int ci,int cj,int gi,int gj){
    queue<pair<int,int>>Q;
    Q.push({ci,cj});
    vst[ci][cj]=true;
    while(!Q.empty()){
        pair<int,int>par=Q.front();
        int x=par.first, y=par.second;
        Q.pop();
        if(x==gi && y==gj)return true;
        for(int i=0; i<4; i++){
            int nx=x+d[i].first;
            int ny=y+d[i].second;
            if (valid(nx,ny)){
                Q.push({nx,ny});
                vst[nx][ny]=true;
            }
        }
    }
    return false;
}
int main(){
    cin>>N>>M;
    int ci=-1, cj=-1, gi=-1, gj=-1;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>A[i][j];
            if(A[i][j]=='A'){
                ci=i;
                cj=j;
            }
            if (A[i][j]=='B'){
                gi=i;
                gj=j;
            }
        }
    }
    if(ci==-1 || cj==-1 || gi==-1 || gj==-1){
        cout<<"NO\n";
     
        return 0;
    }
    memset(vst,false,sizeof(vst));

    if(bfs(ci,cj,gi,gj)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
