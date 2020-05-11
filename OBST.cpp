#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int R[102][102];
double dp[102][102];
vector<int> graph[102];
int root;
bool visited[102];

void optsearchtree(int n, vector<double> p){
    for(int i=1; i<=n; i++){
        dp[i][i-1] = 0;
        dp[i][i] = p[i];
        R[i][i] = i;
        R[i][i-1] = 0;
    }
    dp[n+1][n] = 0;
    R[n+1][n] = 0;
    for(int d=1; d<=n-1; d++){
        for(int i=1; i<=n-d; i++){
            int j=i+d;
            double sum=0; //?~Y~U?| ?~]~X ?~H~D?| ~A?~U? 구?~U| ?~U~P ?~H기?~Y~T
            for(int k=i; k<=j; k++){
                sum+=p[k];
            }
            for(int k=i; k<=j; k++){
                if(dp[i][j] > dp[i][k-1] + dp[k+1][j]+sum){
                    dp[i][j] = dp[i][k-1] + dp[k+1][j]+sum;
                    R[i][j] = k;
                }
            }
        }
    }
}

int make_tree(int i,int j){
    int k=R[i][j];
    if(k==0) return -1;
    else{
        int left=make_tree(i,k-1);
        int right=make_tree(k+1,j);
        if(left !=-1){
            graph[k].push_back(left);
        }
        if(right!=-1){
            graph[k].push_back(right);
        }
        return k;
    }
}
void dfs(int cur){
    cout<<cur<<" ";
    for(int i=0;i<graph[cur].size();i++){
        int next=graph[cur][i];
        if(!visited[next]){
            visited[next]=1;
            dfs(next);
        }
    }
}

int main() {
    ifstream in;
    in.open("input.txt");
    int test;
    in>>test;

    while(test--){

        for(int i=0;i<102;i++)
            for(int j=0;j<102;j++)
                dp[i][j]=100000.0;

        for(int i=0;i<102;i++)
            graph[i].clear();

        fill(&R[0][0], &R[102][102], 0);
        fill(&visited[0], &visited[102], 0);
        int n;
        in>>n;
        vector<double> p(n+1);
        double sum=0;

        for(int i=1; i<=n; i++){
            in>>p[i];
            sum += p[i];
        }
        for(int i=1; i<=n; i++){
            p[i] = p[i]/sum;
        }
        optsearchtree(n,p);
        root=R[1][n];
        make_tree(1,n);
        dfs(root);
        cout<<'\n';
    }
}
