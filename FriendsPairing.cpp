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
/**
 * cant be chaged to dp due to its negetive 
 */
int recc(int n){
    if(n==0) return 1;
    if(n<0) return 0;
    int single = recc(n-1);
    int pair = recc(n-2);
    pair*=(n-1);

    return single+pair;
}
int mod = 1e9+7;

long recc2(int n, vector<int>&dp){
    if(n==0) return dp[n] = 1;
    if(dp[n] != -1) return dp[n];
    long single = recc2(n-1,dp);
    long pair = (n-2 >= 0 ? recc2(n-2,dp) : 0);
    pair= (pair * (n-1))%mod;

    return dp[n] = (single+pair)%mod;
}

long tabu(int n){
    long a = 1, b = 1;
    for(int i=2;i<=n;i++){
        long sum = b + (a*(i-1))%mod;
        a = b;
        b = sum % mod;
    }
    return b;
}


int main(){
    file_i_o();
    cin>>n;
    vector<int>dp(n+1);
    fill(dp.begin(),dp.end(),-1);
    int ans = recc2(n,dp);
    cout<<ans<<endl;
}