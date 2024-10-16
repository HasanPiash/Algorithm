#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,E;
    cin >>N>>E;
    int mat[N][N];
    memset(mat, 0, sizeof(mat));
    while (E--)
    {
        int A,B;
        cin >>A>>B;
        mat[A][B]=1;
        mat[B][A]=1;
    }
    if (mat[3][1]==1)
        cout<<"Connection";
    else
        cout<<"No Connection";
    return 0;
}
