#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long prnt[N],grp_size[N];
void dsu_init(int n){
    for(int i=1; i<=n; i++){
        prnt[i]=-1;
        grp_size[i]=1;
    }
}
int dsu_fnd(int node){
    if(prnt[node]==-1)
        return node;
    prnt[node]=dsu_fnd(prnt[node]);
    return prnt[node];
}
void dsu_unn(int node1,int node2){
    int ldrA=dsu_fnd(node1);
    int ldrB=dsu_fnd(node2);
    if(ldrA!=ldrB){
        if(grp_size[ldrA]>grp_size[ldrB]){
            prnt[ldrB]=ldrA;
            grp_size[ldrA]+=grp_size[ldrB];
        }
        else{
            prnt[ldrA]=ldrB;
            grp_size[ldrB]+=grp_size[ldrA];
        }
    }
}
class Road{
public:
    int U,V;
    long long W;
    Road(int U,int V,long long W){
        this->U=U;
        this->V=V;
        this->W=W;
    }
};
bool cmp(Road a,Road b){
    return a.W<b.W;
}
int main(){
    int N,E;
    cin>>N>>E;
    vector<Road>rdList;
    dsu_init(N);
    for(int i=0; i<E; i++){
        int U,V;
        long long W;
        cin>>U>>V>>W;
        rdList.push_back(Road(U,V,W));
    }
    sort(rdList.begin(),rdList.end(),cmp);
    long long ttlCost=0;
    int eUsed=0;
    for(Road road:rdList){
        int ldrU=dsu_fnd(road.U);
        int ldrV=dsu_fnd(road.V);
        if(ldrU !=ldrV){
            dsu_unn(road.U,road.V);
            ttlCost+=road.W;
            eUsed++;
        }
    }
    if(eUsed==N-1){
        cout<<(E-eUsed)<<" "<<ttlCost<<endl;
    }
    else{
        cout<<"Not Possible"<<endl;
    }
    return 0;
}
