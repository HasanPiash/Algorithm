#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>d={{0,1},{0,-1},{-1,0},{1,0}};
int N,M;
char A[1000][1000];
bool vst[1000][1000];
bool valid(int i,int j){
    if(i<0 || i>=N || j<0 || j>=M)
        return false;
    if(A[i][j] =='#')
        return false;
    return true;
}
void bfs(int ci,int cj){
    queue<pair<int,int>>Q;
    Q.push({ci, cj});
    vst[ci][cj]=true;
    while(!Q.empty()){
        pair<int,int> par=Q.front();
        int x=par.first, y=par.second;
        Q.pop();
        for(int i=0; i<4; i++){
            int ci=x+d[i].first;
            int cj=y+d[i].second;
            if(valid(ci,cj) && !vst[ci][cj]){
                Q.push({ci,cj});
                vst[ci][cj]=true;
            }
        }
    }
}
int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>A[i][j];
        }
    }
    memset(vst,false,sizeof(vst));
    int apartmentCount=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(A[i][j]=='.' && !vst[i][j]){
                apartmentCount++;
                bfs(i,j);
            }
        }
    }
    cout<<apartmentCount<<endl;
    return 0;
}