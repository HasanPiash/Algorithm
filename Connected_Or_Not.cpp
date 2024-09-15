#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,E;
    cin>>N>>E;
    int mat[N][N];
    memset(mat, 0, sizeof(mat));

    while(E--){
        int A,B;
        cin>>A>>B;
        mat[A][B]=1;
    }
    int Q;
    cin>>Q;
    while(Q--){
        int A,B;
        cin>>A>>B;
        if(A==B)
            cout<<"YES\n";
        else if(mat[A][B]==1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}