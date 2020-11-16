#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N,M,K;
bool visited[101][101];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
bool map[101][101];
int si=0;
struct node{
    int x;
    int y;
};
void bfs(int y, int x){
    queue<node> q;
    q.push({x,y});
    visited[y][x]=1;
    si++;

    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        q.pop();

        for(int i=0; i<4; i++){
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if(ny>=N || ny<0 || nx<0 || nx>=M) continue;
            if(!visited[ny][nx] && map[ny][nx]==1){
                visited[ny][nx]=1;
                q.push({nx, ny});
                si++;
            }
        }
    }
}
bool cmp(const int& ret1, const int& ret2){
    return ret1>ret2;
}
int main()
{
    cin>>N>>M>>K;
    for(int i=0; i<K; i++){
        int a,b;
        cin>>a>>b;
        map[a-1][b-1]=1;
    }
    vector<int> ret;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!visited[i][j]&&map[i][j]==1){
                bfs(i,j);
                ret.push_back(si);
                //cout<<si<<'\n';
                si=0;
            }
        }
    }
    sort(ret.begin(), ret.end(), cmp);
    cout<<ret[0]<<endl;
}


