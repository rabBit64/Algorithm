#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int S,E;
    int row[367]={0};
    for(int i=0; i<N; i++){
        cin>>S>>E;
        for(int j=S; j<=E; j++){
            row[j]+=1;
        }
    }
    int idx=0; int maxn=0;
    int ret=0;
    for(int i=0; i<367; i++){
        if(row[i]!=0){
            idx++;
            maxn=max(row[i],maxn);
        }else{
            ret+=idx*maxn;
            idx=0; maxn=0;
        }
    }
    cout<<ret<<endl;

}
