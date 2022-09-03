// Problem Link - 
/* By Arkajyoti Saha */
#include<bits/stdc++.h>
using namespace std;
void file_i_o(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
//######################################################################################################################################################################
int n,m;
void display1D(int *dp){
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
}
void display2D(vector<vector<int>>dp){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int *dp;
int infinitePermutation(int N, int W, int *val, int *wt){
    for(int weight=0;weight<=W;weight++){
        for(int i=0;i<N;i++){
            int w = wt[i];
            if(weight - w>=0){
                dp[weight] = max(dp[weight], dp[weight-w]+val[i]);
            }
        }
    }
    return dp[W];
}

int knapSack(int N, int W, int val[], int wt[]) {
    dp = new int [W+1];
    fill(dp, dp+W+1,0);
    return infinitePermutation(N, W, val, wt);
}


int main(){
    file_i_o();
    int N = 2, W = 3;
    n = N;
    int val[] = {1, 1};
    int wt[] = {2, 1};
    cout<<knapSack(N, W, val, wt)<<endl;
    display1D(dp);
    // cin>>n;
}