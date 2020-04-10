#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[1001];
int cnt[1001]; //node number in each level
vector<int> binarytree[1001]; 

void dfs(int cur, int depth) {
    visited[cur]=1;
    for(int i=0; i<binarytree[cur].size(); i++){
        int child = binarytree[cur][i];
        if(!visited[child]){
            dfs(child, depth+1);
            cnt[depth+1] += 1;
        }
    }
}

int main() {
    int data;
    cin>>data;
    
    while(data--){
        fill(visited, visited+1001, 0); //initialize
        fill(cnt, cnt+1001, 0);
        
        for(int i=0; i<1001; i++) binarytree[i].clear();
        
        int n; //node number
        cin>>n;
        for(int i=0;i<n;i++){
            int cur, left, right;
            
            cin>>cur>>left>>right;
            if(left!=-1) binarytree[cur].push_back(left);
            if(right!=-1) binarytree[cur].push_back(right);
        }
        
        dfs(1,1);
        int mst=0;
        int idx=0;
        for(int i=0; i<1001; i++) {
            if(cnt[i] > mst) {
                mst = cnt[i];
                idx = i;
            }
        }    
        cout<<idx<<endl;
    }
}
