#include<bits/stdc++.h>
using namespace std;
void file_i_o(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
void display2D(vector<vector<int>>dp){
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
/**
 * @brief SINGLE COIN SUPPLY HAS BEEN GIVE
 */
vector<vector<int>>dp;
int combination(vector<int>&arr, int tar, int n){
    if(n==0 or tar ==0) return dp[tar][n] = (tar == 0 ? 1 : 0);

    if(dp[tar][n] !=-1) return dp[tar][n];

    bool flag = false;
    if(tar - arr[n-1] >= 0)
        flag = flag or combination(arr, tar-arr[n-1], n-1) == 1;
    flag = flag or combination(arr,tar, n-1);

    return dp[tar][n] = flag ? 1 : 0;
}

bool isSubsetSum(vector<int>arr, int sum){
    dp.resize(sum+1, vector<int>(arr.size()+1,-1));
    return combination(arr, sum, arr.size()); 
}

int main(){
    file_i_o();
    cout<<isSubsetSum({2,3,5,7} ,10)<<endl;
    display2D(dp);
}