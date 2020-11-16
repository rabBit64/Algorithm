#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int N, K, S, x, y;
int map[201][201];
int dir[4][2]={0,1,0,-1,-1,0,1,0};

struct loc{
    int y;
    int x;
    int cnt;
};   

vector<vector<loc>> v(1001);

void bfs(){
    queue<loc> q;
    for(int i=1;i<=K;i++){
        //q.push(v[i]);
        for(int j=0;j<v[i].size();j++){
            q.push(v[i][j]);
        }
    }

    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int cnt=q.front().cnt;
        q.pop();
        
        if(cnt==S){
            return;
        }

        for(int i=0; i<4; i++){
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if(nx>N || nx<1 || ny>N || ny<1) continue;
            if(map[ny][nx]==0){
                map[ny][nx]=map[y][x];
                q.push({ny,nx,cnt+1});
            }
            
        }
    }

}


int main(){
    cin>>N>>K;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>map[i][j];
            if(map[i][j]!=0){
                //v[map[i][j]]={i,j,0};
                v[map[i][j]].push_back({i,j,0});
            }
        }
    }
    cin>>S>>x>>y;
    bfs();

    cout<<map[x][y]<<endl;
}
