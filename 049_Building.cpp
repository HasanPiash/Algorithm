#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long prnt[N];
long long grp_size[N];
void dsu_init(long long n){
    for(long long i=1; i<=n; i++){
        prnt[i]=-1;
        grp_size[i]=1;
    }
}
long long dsu_fnd(long long node){
    if(prnt[node]==-1)
        return node;
    prnt[node]=dsu_fnd(prnt[node]);
    return prnt[node];
}
void dsu_unnsize(long long node1,long long node2){
    long long ldrA=dsu_fnd(node1);
    long long ldrB=dsu_fnd(node2);
    if(ldrA !=ldrB){
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
class Building{
public:
    long long U,V,W;
    Building(long long U,long long V,long long W){
        this->U=U;
        this->V=V;
        this->W=W;
    }
};
bool cmp(Building a,Building b){
    return a.W<b.W;
}
int main(){
    long long N,E;
    cin>>N>>E;
    dsu_init(N);
    vector<Building>eList;
    for(long long i=0; i<E; i++){
        long long U,V,W;
        cin>>U>>V>>W;
        eList.push_back(Building(U,V,W));
    }
    sort(eList.begin(),eList.end(),cmp);
    long long ttlCost=0;
    long long eUsed=0;
    for(Building ed:eList){
        long long ldrU=dsu_fnd(ed.U);
        long long ldrV=dsu_fnd(ed.V);
        if(ldrU !=ldrV){
            dsu_unnsize(ed.U,ed.V);
            ttlCost+=ed.W;
            eUsed++;
            if(eUsed==N-1)
                break;
        }
    }
    if(eUsed==N-1){
        cout<<ttlCost<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}
