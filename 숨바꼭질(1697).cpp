#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int N,K;
bool visited[100001];
struct loc{
    int x;
    int cnt;
};
void bfs(){
    queue<loc> q;
    q.push({N,0});
    while(!q.empty()){
        int x=q.front().x;
        int cnt=q.front().cnt;
        q.pop();
        
        if(x==K){
            cout<<cnt<<'\n';
            return;
        }
        if(x+1<=100000&&visited[x+1]!=1){
            int nx=x+1;
            visited[nx]=1;
            q.push({nx,cnt+1});
        }
        if(x-1>=0&&visited[x-1]!=1){
            int nx=x-1;
            visited[nx]=1;
            q.push({nx,cnt+1});
        }
        if(x*2<=100000&&visited[x*2]!=1){
            int nx=x*2;
            visited[nx]=1;
            q.push({nx,cnt+1});
        }

    }
    
}
int main(){
    cin>>N>>K;
    bfs();

}
