#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int N,M;
int map[1001][1001];
struct loc{
    int y;
    int x;
    int ti;
    
};
vector<loc> t;
vector<loc> z;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
bool visited[1001][1001];
void bfs(){
    queue<loc> q;
    //출발할 때 시작지점 다 넣어주기
    for(int i=0; i<t.size(); i++){
        q.push({t[i].y, t[i].x, 0});
    }
    int cnt=z.size();
    if(cnt==0){
        cout<<0<<'\n';
        return;
    }
    int day=0;
    while(!q.empty()){
    
        int si=q.size();
        for(int i=0;i<si;i++){
            int x=q.front().x;
            int y=q.front().y;
            int ti=q.front().ti;
            q.pop();
        
            for(int i=0; i<4; i++){
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];
                if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
                if(map[ny][nx]==0){
                    map[ny][nx]=1;
                    cnt-=1;
                    q.push({ny,nx, ti+1});
                }
            }
        }
        day++;
        if(cnt==0){
            cout<<day<<'\n';
            return;
        }
    }
    cout<<-1<<endl;
    return;
    
}

int main(){
    cin>>N>>M;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
            if(map[i][j]==1){
                t.push_back({i,j,0});    
            }else if(map[i][j]==0){
                z.push_back({i,j,0});
            }
        }
    }
    bfs();
}
