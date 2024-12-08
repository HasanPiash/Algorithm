#include<bits/stdc++.h>
using namespace std;
const int MAX = 1005;
char grid[MAX][MAX];
bool vstd[MAX][MAX];
long long int N,M;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
bool isVld(long long int x,long long int y){
    return (x>=0 && x<N && y>=0 && y<M && !vstd[x][y] && grid[x][y]=='.');
}
long long int bfs(long long int sX,long long int sY){
    queue<pair<long long int,long long int>>q;
    q.push({sX,sY});
    vstd[sX][sY]=true;
    long long int size=1;
    while(!q.empty()){
        long long int x=q.front().first;
        long long int y=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            long long int newX =x+dx[i];
            long long int newY=y+dy[i];
            if(isVld(newX,newY)){
                vstd[newX][newY]=true;
                q.push({newX,newY});
                size++;
            }
        }
    }
    return size;
}
int main(){
    cin>>N>>M;
    for(long long int i=0; i<N; i++){
        for(long long int j=0; j<M; j++){
            cin>>grid[i][j];
        }
    }
    memset(vstd,false,sizeof(vstd));
    long long int minArea=LLONG_MAX;
    bool Cmpnnt=false;
    for(long long int i=0; i<N; i++){
        for(long long int j=0; j<M; j++){
            if(grid[i][j]=='.' && !vstd[i][j]){
                Cmpnnt=true;
                long long int area=bfs(i,j);
                minArea=min(minArea,area);
            }
        }
    }
    if(Cmpnnt){
        cout<<minArea<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}
