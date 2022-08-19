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
void display2D(int **dp, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int fiboMemo(int n, int *dp){
    if(n<=1) return dp[n] = n;
    if(dp[n] != -1) return dp[n];
    int ans = fiboMemo(n-1, dp) + fiboMemo(n-2, dp);
    return dp[n] = ans; 
}


int main(){
    file_i_o();
    int n;
    cin>>n;
    int dp[n+1];
    fill(dp, dp+n+1, -1);
    cout<<fiboMemo(n,dp)<<endl;
    display1D(dp,n+1);
}