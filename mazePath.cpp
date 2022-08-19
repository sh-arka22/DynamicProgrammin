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
void display1D(int *dp, int n){
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
}
void display2D(vector<vector<int>>&dp, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int dir[3][2] = {{-1,-1},{-1,0},{0,-1}};

int mazePath_jump(int n, int m,vector<vector<int>>&dp){
    if(n==0 and m==0){
        return dp[n][m] = 1;
    }
    if(dp[n][m]!= -1) return dp[n][m];
    int count = 0;
    for(auto &[dr,dc]:dir){
        int r = (n+dr), c = (m+dc);
        while(r>=0 and c>=0 and r<dp.size() and c<dp[0].size()){
            count += mazePath_jump(r,c,dp);
            r+=dr, c+=dc;
        }   
    }
    return dp[n][m] = count;
}

int mazePath(int n, int m,vector<vector<int>>&dp){
    if(n==0 and m==0){
        return dp[n][m] = 1;
    }
    if(dp[n][m]!= -1) return dp[n][m];
    int count = 0;
    for(auto &[dr,dc]:dir){
        int r = n+dr, c = m+dc;
        if(r>=0 and c>=0 and r<dp.size() and c<dp[0].size())
            count += mazePath(r,c,dp);
    }
    return dp[n][m] = count;
}

int main(){
    file_i_o();
    int n,m;
    cin>>n>>m;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    cout<<mazePath_jump(n-1,m-1,dp)<<endl;
    display2D(dp,n,m);

}