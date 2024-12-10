#include<bits/stdc++.h>
using namespace std;
class CycleEdges{
public:
    vector<int>prnt,rnk;
    CycleEdges(int n){
        prnt.resize(n+1);
        rnk.resize(n+1,0);
        for(int i=1; i<=n; i++){
            prnt[i]=i;
        }
    }
    int find(int x){
        if(prnt[x] !=x){
            prnt[x]=find(prnt[x]);
        }
        return prnt[x];
    }
    bool CclSet(int x,int y){
        int rootX=find(x);
        int rootY=find(y);
        if(rootX !=rootY){
            if(rnk[rootX]>rnk[rootY]){
                prnt[rootY]=rootX;
            }
            else if(rnk[rootX]<rnk[rootY]){
                prnt[rootX]=rootY;
            }
            else{
                prnt[rootY]=rootX;
                rnk[rootX]++;
            }
            return true;  
        }
        return false; 
    }
};

int main(){
    int N,E;
    cin>>N>>E;
    CycleEdges ce(N);
    int clEdg=0;
    for(int i=0; i<E; i++){
        int A,B;
        cin>>A>>B;
        if(!ce.CclSet(A,B)){
            clEdg++;
        }
    }
    cout<<clEdg<<endl;
    return 0;
}
