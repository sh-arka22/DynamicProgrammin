// Problem Link - https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
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
const static int N = 1001;
vector<vector<int>>dp(N, vector<int>(N,-1));

int knapSack(int W, int wt[], int val[], int n) {
    if(n == 0 or W <= 0) return dp[n][W] = 0;

    if(dp[n][W] != -1) return dp[n][W];

    int maxValue = 0 ;

    if(W - wt[n-1] >= 0){
        maxValue = max(maxValue, knapSack(W-wt[n-1], wt, val, n-1) + val[n-1]);
    }
    maxValue = max(maxValue, knapSack(W, wt, val, n-1));

    return dp[n][W] = maxValue;
}


int main(){
    file_i_o();
    int wt[] = {4,5,1};
    int val[] = {1,2,3};
    cout<<knapSack(3,wt,val, 3);
}