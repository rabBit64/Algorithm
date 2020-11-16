#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int F,S,G,U,D;
bool visited[1000001];
struct stair{
    int x;
    int cnt;
};
void bfs(){
    queue<stair> q;
    q.push({S,0});
    visited[S]=1;
    while(!q.empty()){
        int x=q.front().x;
        int cnt=q.front().cnt;
        q.pop();
        if(x==G){
            cout<<cnt<<'\n';
            return;
        }
        if(x-D>0&&visited[x-D]==0){
            int nx=x-D;
            visited[nx]=1;
            q.push({nx,cnt+1});
        }
        if(x+U<=F&&visited[x+U]==0){
            int nx=x+U;
            visited[nx]=1;
            q.push({nx, cnt+1});
        }
    }
    cout<<"use the stairs\n";
}
int main(){
    cin>>F>>S>>G>>U>>D;
    bfs();
}
