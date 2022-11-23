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
class Solution {
private:
    vector<vector<int>>dp;
    int recc(vector<int>&nums, int si, int ei){

        int lele = si == 0 ? 1 : nums[si-1];
        int rele = ei == size(nums)-1 ? 1 : nums[ei+1];
        if(dp[si][ei] != -1) return dp[si][ei];
        int maxi = 0;
        for(int cut=si; cut<=ei; cut++){
            int lcost = cut == si ? 0 : recc(nums, si, cut-1);
            int rcost = cut == ei ? 0 : recc(nums, cut+1, ei);

            maxi = max(maxi, lcost + lele * nums[cut] * rele + rcost);
        }
        return dp[si][ei] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = size(nums);
        dp.resize(n+1, vector<int>(n+1, -1));
        return recc(nums, 0, n-1);
    }
};