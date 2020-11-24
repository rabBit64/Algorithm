/* 중복제외 순열 */
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
int arr[9];
bool visited[9];
vector<int> sel;
void f(int cur){
    if(sel.size()==M){
        for(int i=0; i<sel.size(); i++){
            cout<<sel[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i=0; i<N; i++){
        if(!visited[i]){
            visited[i]=1;
            sel.push_back(arr[i]);
            f(i+1);
            sel.pop_back();
            visited[i]=0;
        }
    }
}

int main()
{
    cin>>N>>M;
    
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    sort(arr, arr+N);
    f(0);
}
