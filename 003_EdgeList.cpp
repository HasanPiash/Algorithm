#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,E;
    cin>>N>>E;
    vector<pair<int,int>>V;
    while (E--)
    {
        int A,B;
        cin>>A>>B;
        V.push_back({A,B});
    }
    for(auto P:V)
    {
        cout<<P.first<<" "<<P.second<<endl;
    }
    return 0;
}
