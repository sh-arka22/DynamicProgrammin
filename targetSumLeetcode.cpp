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
vector<vector<int>>dp;
// map<pair<int,int>,int>dp;
//shifting from targrt to zero
int recc(vector<int> &nums, int n, int tar, int sum){
    if(n==0) return dp[n][tar] = (tar==sum);
    if(dp[n][tar] != -1) return dp[n][tar];
    int cnt = 0;

    if(tar - (nums[n-1]) >= 0) cnt += recc(nums,n-1, tar - (nums[n-1]), sum);
    if(tar - (-nums[n-1]) <= 2*sum) cnt += recc(nums,n-1, tar - (-nums[n-1]), sum);

    return dp[n][tar] = cnt;
}

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(begin(nums), end(nums), 0);
    if(sum < target or sum < -target) return 0;
    dp.resize(nums.size()+1, vector<int>(2*sum+1, -1));
    return recc(nums,nums.size(), sum + target, sum);
}

int main(){
    file_i_o();
    cin>>n;
}
