#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int M[501][501];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
bool visited[501][501];
int si=0;
int n,m;
struct loc{
    int x;
    int y;
};
void bfs(int cury, int curx){
    visited[cury][curx]=1;
    queue<loc> q;
    q.push({curx,cury});
    si++;
    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if(nx>=0&&nx<m&&ny>=0&&ny<n&&visited[ny][nx]==0&&M[ny][nx]==1){
                visited[ny][nx]=1;
                q.push({nx,ny});
                si++;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>M[i][j];
        }
    }
    vector<int> ret;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(M[i][j]==1&&visited[i][j]==0){
                bfs(i,j);
                ret.push_back(si);
                si=0;
            }
        }
    }
    cout<<ret.size()<<'\n';
    if(ret.size()==0){
        cout<<0<<endl;
    }else {
        int maxr = *max_element(ret.begin(), ret.end());
        cout<<maxr<<endl;
    }
}
