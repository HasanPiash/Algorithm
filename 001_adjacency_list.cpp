#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,E;
    cin>>N>>E;
    vector<int> mat[N];
    while (E--)
    {
        int A,B;
        cin>>A>>B;
        mat[A].push_back(B);
        mat[B].push_back(A);
    }
    vector<int>V;
    for (int i = 0; i < mat[3].size(); i++)
    {
        cout << mat[3][i] << " ";
    }
    return 0;
}
