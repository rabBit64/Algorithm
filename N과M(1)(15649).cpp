#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<int> sel;
bool visited[9];
void f(int cur){
    if(sel.size()==M){
        for(int i=0; i<sel.size(); i++){
            cout<<sel[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            visited[i]=1;
            sel.push_back(i);
            f(i+1);
            sel.pop_back();
            visited[i]=0;
        }
    }
}

int main()
{
    cin>>N>>M;
    f(1);
}
