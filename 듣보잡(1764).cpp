#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin>>N>>M;
    set<string> n;//듣지 못한 사람
    string a;
    for(int i=0; i<N; i++){
        cin>>a; //듣지 못한 사람
        n.insert(a);
    }
    vector<string> result;
    
    for(int i=0; i<M; i++){
        cin>>a; //보지 못한 사람
        if(n.find(a) != n.end()){//존재
            result.push_back(a);   
        }
    }
    cout<<result.size()<<'\n'; //사전순
    sort(result.begin(), result.end());
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<'\n';   
    }
}
