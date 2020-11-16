#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[1001];
int visited[1001];

void bfs(int cur){
    queue<int> q;
    q.push(cur);
    visited[cur]=1;
    
    while(!q.empty()){
        int x=q.front();
        q.pop();
        
        for(int i=0; i<adj[x].size(); i++){
            int nx=adj[x][i];
            
            if(!visited[nx]){
                q.push(nx);
                visited[nx]=1;
            }
        }
    }
}

int main()
{
  int N,M;
  cin>>N>>M;
  
  for(int i=0; i<M; i++){
      int a,b;
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
  }
  
  int ret=0;
  for(int i=1; i<=N; i++){
    if(!visited[i]){
        bfs(i);
        ret++;
    }
  }
  cout<<ret<<endl;
}
