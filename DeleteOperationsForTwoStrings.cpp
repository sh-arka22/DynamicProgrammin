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
void display2D(int **dp){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int solve(int N,int M,string text1, string text2,vector<vector<int>>&dp){

for(int n=0;n<=N;n++){
    for(int m=0;m<=M;m++){
        if(n==0 || m==0){
            dp[n][m] = 0;
            continue;
        }
        if(text1[n-1]==text2[m-1]){
            dp[n][m] = dp[n-1][m-1]+1;
        }
        else{
            dp[n][m]=max(dp[n-1][m],dp[n][m-1]);
        }
    }
}

return dp[N][M];
}

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int ans = solve(n,m, text1,  text2,dp);
return ans;
}

int minDistance(string word1, string word2) {
    int comLen = longestCommonSubsequence(word1, word2);
    int n = word1.length();
    int m = word2.length();
    
    return (n+m-2*(comLen));
}

int main(){
    file_i_o();
    cin>>n;
}