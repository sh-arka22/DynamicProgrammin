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
int recc(vector<int>&nums, int ei){
    if(ei == 0) return dp[ei] = 1;
    if(dp[ei] != 0) return dp[ei];
    int maxLen = 1;
    for(int i = ei-1;i>=0;i--){
        if(nums[i] >= nums[ei]) continue;
        int faith = recc(nums, i);
        maxLen = max(maxLen, faith+1);
    }
    return dp[ei] = maxLen;
}

//method2
int lengthOfLIS(vector<int>& nums) {
    return solve(nums, 0, INT_MIN);
}
int solve(vector<int>& nums, int i, int prev) {
    if(i >= size(nums)) return 0;                                // cant pick any more elements
    
    int pick = (nums[i] > prev) ? solve(nums, i + 1, nums[i])+1 : 0;
    int dontPick = solve(nums, i+1, prev);
    
    return max(pick, dontPick);
}

int solve(vector<int>& nums, int i, int prev) {
    if(i >= size(nums)) return 0;                                // cant pick any more elements
    
    int pick = (nums[i] > prev) ? solve(nums, i + 1, nums[i])+1 : 0;
    int dontPick = solve(nums, i+1, prev);
    
    return max(pick, dontPick);
}


int tabu(vector<int>& nums){
    int n = nums.size(), maxLen = 0;

    for(int i=0;i<n;i++){
        dp[i] = 1;
        for(int j=i-1;j>=0;j--){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], dp[j] + 1); 
            }
        }
        maxLen = max(maxLen,dp[i]);
    }
    return maxLen;
}

int lengthOfLIS(vector<int>&nums) {
    dp = new int[nums.size()];
    fill(dp,dp+nums.size(),0);
    int maxLen = 0;
    for(int i=0;i<nums.size();i++){
        maxLen = max(maxLen, recc(nums, i));
    }
    return maxLen;
}

int main(){
    file_i_o();
    vector<int> nums;
    int x;
    while(cin>>x) nums.push_back(x);
    // int ans = lengthOfLIS(nums);
    int tab = tabu(nums);
    cout<<tab;
}
