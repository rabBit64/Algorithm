#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void binsearch(int key, vector<long long>& c);
int main(){
    int M,N;
    cin>>M>>N;
    vector<long long> c(N);
    for(int i=0; i<N; i++){
        cin>>c[i];
    }
    binsearch(M,c);
}
void binsearch(int key, vector<long long>& c){
    long long left=1;
    long long right=*max_element(c.begin(), c.end());
    while(left<=right){
        long long mid=(left+right)/2; //x
        long long f=0; //y
        for(int i=0; i<c.size(); i++){
            f+=c[i]/mid;
        }
        if(f<key){
            right=mid-1;
        }else if(f>=key){
            left=mid+1;
        }
    }
    cout<<right<<endl;
}
