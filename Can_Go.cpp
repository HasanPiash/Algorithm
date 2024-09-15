HackerRank Home
HackerRank
|
Prepare
Certify
Compete
Apply
Search
 
All Contests  Assignment 01 | Introduction to Algorithms | Batch 05  Can Go?
Can Go?
Problem
Submissions
Leaderboard
Discussions
Problem Statement

You are given an  sized 2D matrix that represents a map of a building. Each cell represents a wall, a floor or a room. You will be given two rooms  and . You need to tell if you can go from room  to  by passing through the floors. You can walk left, right, up, and down through the floor cells. You can't pass through walls.

Input Format

The first input line has two integers  and : the height and width of the map.
Then there are  lines of  characters describing the map. Each character is .(floor), #(wall), A or B (rooms).
Constraints

Output Format

Output YES if you can go from room  to , NO otherwise.
Sample Input 0

5 8
########
#.A#...#
#.##.#B#
#......#
########
Sample Output 0

YES
Submissions: 474
Max Score: 20
Difficulty: Easy
Rate This Challenge:

    
More
 
g
1
#include<bits/stdc++.h>
2
using namespace std;
3
bool vst[1000][1000];
4
vector<pair<int,int>>d={{0,1},{0,-1},{-1,0},{1,0}};
5
int N,M;
6
char A[1000][1000];
7
bool valid(int i,int j){
8
    if(i<0 || i>=N || j<0 || j>=M)return false;
9
    if(A[i][j]=='#' || vst[i][j])return false;
10
    return true;
11
}
12
bool bfs(int ci,int cj,int gi,int gj){
13
    queue<pair<int,int>>Q;
14
    Q.push({ci,cj});
15
    vst[ci][cj]=true;
16
    while(!Q.empty()){
17
        pair<int,int>par=Q.front();
18
        int x=par.first, y=par.second;
19
        Q.pop();
20
        if(x==gi && y==gj)return true;
21
        for(int i=0; i<4; i++){
22
            int nx=x+d[i].first;
23
            int ny=y+d[i].second;
24
            if (valid(nx,ny)){
25
                Q.push({nx,ny});
26
                vst[nx][ny]=true;
27
            }
28
        }
29
    }
30
    return false;
31
}
32
int main(){
33
    cin>>N>>M;
34
    int ci=-1, cj=-1, gi=-1, gj=-1;
35
    for(int i=0; i<N; i++){
36
        for(int j=0; j<M; j++){
37
            cin>>A[i][j];
38
            if(A[i][j]=='A'){
39
                ci=i;
40
                cj=j;
41
            }
42
            if (A[i][j]=='B'){
43
                gi=i;
44
                gj=j;
45
            }
46
        }
47
    }
48
    if(ci==-1 || cj==-1 || gi==-1 || gj==-1){
49
        cout<<"NO\n";
50
        return 0;
51
    }
52
    memset(vst,false,sizeof(vst));
53
    if(bfs(ci,cj,gi,gj)){
54
        cout<<"YES\n";
55
    }
56
    else{
57
        cout<<"NO\n";
58
    }
59
    return 0;
60
}
Line: 20 Col: 25
Run Code Submit CodeUpload Code as File 
Test against custom input
Testcase 0
Congratulations, you passed the sample test case.

Click the Submit Code button to run your code against all the test cases.

Input (stdin)

5 8
########
#.A#...#
#.##.#B#
#......#
########
Your Output (stdout)

YES
Expected Output

YES
Interview Prep | Blog | Scoring | Environment | FAQ | About Us | Support | Careers | Terms Of Service | Privacy Policy |

