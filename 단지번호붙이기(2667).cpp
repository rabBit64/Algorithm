#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
bool visited[25][25];
int si=0;
int N;
vector<string> S(25);
int dir[4][2]={1,0,0,1,-1,0,0,-1};
struct house{
    int x;
    int y;
};
void bfs(int curx,int cury){
    visited[cury][curx]=1;
    queue<house> q;
    q.push({curx,cury});
    si++;
    while(!q.empty()){        
        int x=q.front().x;
        int y=q.front().y;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if(nx<N && nx>=0 && ny<N && ny>=0 && visited[ny][nx]==0&&S[ny][nx]=='1'){
                visited[ny][nx]=1;
                q.push({nx,ny});
                si++;
            }
        }
    }
    
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>S[i];
    }
    vector<int> ret;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(S[i][j]=='1'&&visited[i][j]==0){
                bfs(j,i);
                ret.push_back(si);
                si=0;
            }
        }
    }
    sort(ret.begin(), ret.end());
    cout<<ret.size()<<'\n';
    for(int i=0; i<ret.size(); i++){
        cout<<ret[i]<<endl;   
    }
}
