#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
using namespace std;
int k;
char cmp[10];
bool visited[10];
vector<int> sel;
int num[10]={0,1,2,3,4,5,6,7,8,9};
vector<vector<int>> ret; 
void f(int cur){
    if(sel.size()==k+1){
         for(int i=0; i<k; i++){
             if(cmp[i]=='<'){
                 if(sel[i]<sel[i+1]) continue;
                 else return;
             }else if(cmp[i]=='>'){
                 if(sel[i]>sel[i+1]) continue;
                 else return;
             }
         }
        ret.push_back(sel);
    }
    for(int i=0; i<10; i++){
        if(!visited[i]){
            visited[i]=1;
            sel.push_back(num[i]);
            f(i+1);
            sel.pop_back();
            visited[i]=0;
        }
    }
}

int main(){
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>cmp[i];
    }
    f(0); //중복제외 순열
    for(int i=0; i<ret.back().size(); i++){
        cout<<ret.back()[i];
    }
    cout<<'\n';
    for(int i=0; i<ret.front().size(); i++){
        cout<<ret.front()[i];
    }
}
