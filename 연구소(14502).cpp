#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;


struct loc{
    int y;
    int x;
};

int map[9][9];
int cpmap[9][9];
vector<loc> v;
vector<loc> s;
int N,M;
int dir[4][2]={1,0,0,1,-1,0,0,-1};

int ret=-1;

void bfs(int l1, int l2, int l3){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cpmap[i][j]=map[i][j];
        }
    }
    cpmap[s[l1].y][s[l1].x]=1;
    cpmap[s[l2].y][s[l2].x]=1;
    cpmap[s[l3].y][s[l3].x]=1;
    
    int cnt=s.size()-3;
    queue<loc> q;
    for(long unsigned int i=0; i<v.size(); i++){
        q.push(v[i]);
    }
    
    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if(ny>=N || ny<0 || nx>=M || nx<0) continue;
            if(cpmap[ny][nx]==0){
                cpmap[ny][nx]=2;
                q.push({ny,nx});
                cnt-=1;
            }
        }
    }
    if(cnt>ret){
        ret=cnt;
    }
}

int main(){
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
            if(map[i][j]==2){
                v.push_back({i,j});
            }else if(map[i][j]==0){
                s.push_back({i,j});
            }
        }
    }
    
    for(long unsigned int i=0; i<s.size(); i++){
        for(long unsigned int j=i+1; j<s.size(); j++){
            for(long unsigned int k=j+1; k<s.size(); k++){
                bfs(i,j,k);
            }
        }
    }
    cout<<ret<<endl;
    
}
