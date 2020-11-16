#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int l,c[2],n[2];
int dir[8][2]={2,1,1,2,-1,2,-2,1,2,-1,1,-2,-1,-2,-2,-1};
//int visited[300][300];
struct chess{
    int x;
    int y;
    int cnt;
};
void bfs(){
    queue<chess> q;
    vector<vector<bool>> visited(l+1, vector<bool>(l+1,0));
    q.push({c[0],c[1],0});
    visited[c[1]][c[0]]=1;
    
    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int cnt=q.front().cnt;
        q.pop();
    
        if(x==n[0]&&y==n[1]){
            cout<<cnt<<'\n';
            return;
        }
        for(int i=0; i<8; i++){
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if(nx>=l||nx<0||ny>=l||ny<0) continue;
            if(visited[ny][nx]==0){
                visited[ny][nx]=1;
                q.push({nx,ny,cnt+1});
            }
        
        }
     }
    
    
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>l;
        cin>>c[0]>>c[1];
        cin>>n[0]>>n[1];
        bfs();
    }
}
