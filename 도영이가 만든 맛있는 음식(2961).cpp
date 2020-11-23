#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
struct food{
    int S;
    int B;
};
vector<food> F;
long long totals=1;
long long totalb=0;
long long ret=1000000001;
void f(int cur){
    for(int i=cur; i<F.size(); i++){
        totals*=F[i].S;
        totalb+=F[i].B;
        ret=min(abs(totals-totalb),ret);
        f(i+1);
        totals/=F[i].S;
        totalb-=F[i].B;
    }
}
int main(){
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int a,b;
        cin>>a>>b;
        F.push_back({a,b});
    }
    f(0);
    cout<<ret<<endl;
}
