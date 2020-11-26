#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
using namespace std;

vector<int> graph[100001];
bool visited[100001];
int parent[100001];

void dfs(int node){
    for(int i=0;i<graph[node].size();i++){
        int next_node=graph[node][i];
        if(!visited[next_node]){
            visited[next_node]=1;
            parent[next_node]=node;
            dfs(next_node);
        }
    }
}

int main(){
   int n;
   cin>>n;
   for(int i=0;i<n-1;i++){
       int x,y;
       cin>>x>>y;
       graph[x].push_back(y);
       graph[y].push_back(x);
   }
   dfs(1);
   for(int i=2;i<=n;i++){
       cout<<parent[i]<<'\n';
   }
}
