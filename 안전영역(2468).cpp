#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N; int si=0;
int map[101][101];
bool visited[101][101];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
struct loc{
    int y;
    int x;
};
void rain(int amount){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            visited[i][j]=0;
            if(map[i][j]<=amount){
                visited[i][j]=1;
            }   
        }   
    }
}
void bfs(int cury, int curx){
    visited[cury][curx]=1;
    queue<loc> q;
    q.push({cury, curx});
    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        q.pop();
        for(int i=0; i<4; i++){
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if(nx>=N || nx<0 || ny>=N || ny<0) continue;
            if(!visited[ny][nx]){
                visited[ny][nx]=1;
                q.push({ny, nx});
            }
        }
    }
}

int main()
{
    cin>>N;
    int maxn=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
            maxn=max(map[i][j],maxn);
        }   
    }
    int ret=0;
    for(int i=0; i<=maxn; i++){
        rain(i);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(visited[i][j]==0){
                    bfs(i,j);
                    si++;
                }
            }
        }
        ret=max(si, ret);
        si=0;
    }
    cout<<ret<<'\n';

}
