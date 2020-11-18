#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int N, M;
int map[51][51];
struct loc{
    int y;
    int x;
};
vector<loc> v;
vector<loc> z;
vector<int> sel;
int ret=1000000001;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int bfs(){
    vector<vector<int>> map2(N,vector<int>(N,0)); //2차원 벡터 초기화
    for(int i=0; i<N; i++){ //copy
        for(int j=0; j<N; j++){
            map2[i][j]=map[i][j];
        }
    }
    
    queue<loc> q;
    
    for(int i=0; i<sel.size(); i++){
        q.push(v[sel[i]]);//sel[i] -> 선택한 v의 인덱스
        map2[v[sel[i]].y][v[sel[i]].x]=3;
    }
    int cnt=z.size()+v.size()-sel.size();
    if(cnt==0){
        return 0;
    }
    
    int time=0;
    while(!q.empty()){
        int si=q.size();
        for(int i=0; i<si; i++){
            int x=q.front().x;
            int y=q.front().y;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];
                if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                if(map2[ny][nx]==0 || map2[ny][nx]==2){
                    map2[ny][nx]=3;
                    cnt--;
                    q.push({ny,nx});
                }
            }
        }
        time++;
        if(cnt==0){
            return time;
        }
    }
    return 1000000001;
}

void f(int cur){
    if(sel.size()==M){    
        ret=min(ret,bfs());
        return;
    }
    for(int i=cur; i<v.size(); i++){
        sel.push_back(i);
        f(i+1);
        sel.pop_back();
    }
}


int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
            if(map[i][j]==2){
                v.push_back({i,j});
            }else if(map[i][j]==0){
                z.push_back({i,j});       
            }
        }
    }
    f(0);
    if(ret>100000000){
        cout<<-1<<endl;
    }
    else{
        cout<<ret<<'\n';
    }
}
