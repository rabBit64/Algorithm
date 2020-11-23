#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, S;
int arr[21];
int sum=0;
int cnt=0;
vector<int> sel;
void f(int cur){
    if(sum==S && sel.size()>0){
        cnt++;
    }
    for(int i=cur; i<N; i++){
        sel.push_back(arr[i]);
        sum+=arr[i];
        f(i+1);
        sum-=arr[i];
        sel.pop_back();
    }

}

int main()
{
    cin>>N>>S;
    
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    f(0);
    cout<<cnt<<endl;
}
