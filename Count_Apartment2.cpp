#include<bits/stdc++.h>
using namespace std;
char A[1000][1000];
bool vst[1000][1000];
vector<pair<int,int>>d={{0,1},{0,-1},{-1,0},{1,0}}; 
int N,M;
bool valid(int i,int j){
    if(i<0 || i>=N || j<0 || j>=M)return false;
    if(A[i][j]=='#')return false;
    return true;
}
int dfs(int si,int sj){
    vst[si][sj]=true;
    int roomCount=1;
    for(int i=0; i<4; i++){
        int ci=si+d[i].first;
        int cj=sj+d[i].second;
        if(valid(ci,cj) && !vst[ci][cj])
        {
            roomCount+=dfs(ci,cj);
        }
    }
    return roomCount;
}
int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>A[i][j];
        }
    }
    memset(vst,false,sizeof(vst));
    vector<int>apartmentSizes;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(A[i][j]=='.' && !vst[i][j]){
                int apartmentSize=dfs(i,j);
                apartmentSizes.push_back(apartmentSize);
            }
        }
    }
    if(apartmentSizes.empty())
    {
        cout<<0<<endl;
    }
    else{
        sort(apartmentSizes.begin(),apartmentSizes.end());
        for(int size:apartmentSizes)
        {
            cout<<size<<" ";
        }
        cout<<endl;
    }
    return 0;
}