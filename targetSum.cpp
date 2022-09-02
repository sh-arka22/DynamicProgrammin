#include<bits/stdc++.h>
using namespace std;
void file_i_o(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
//************************************************************************************************

int permutation(vector<int>nums, int tar){
	if(tar==0) return 1;
	int cnt = 0;
	for(auto ele:nums){
		if(tar - ele >= 0)
			cnt += permutation(nums, tar-ele);
	}
	return cnt;
}
int *dp;
int permutationTable(vector<int>nums, int Tar){
	dp[0] = 1;
	for(int tar = 1; tar<=Tar; tar++){
		int cnt = 0;
		for(auto ele:nums){
			if(tar - ele >= 0){
				cnt += dp[tar-ele];
			}
		}
		dp[tar] = cnt;
	}
	return dp[Tar];
}

//works when we are hgiven infinite supply of coins, cannot be used for single supply of coins
int combinationTable(vector<int>nums, int Tar){
	dp[0] = 1;
	for(auto ele:nums){
		for(int tar = ele; tar<=Tar; tar++){
			int cnt = 0;
				if(tar - ele >= 0)
					cnt += dp[tar-ele];
			dp[tar] += cnt;
		}
	}
	return dp[Tar];
}

int combination(vector<int>nums, int n, int tar){
	if(tar==0) return 1;
	int cnt = 0;
	for(int i=n;i>=0;i--){
		if(tar - nums[i] >= 0)
			cnt += combination(nums, i, tar- nums[i]);
	}
	return cnt;
}

int main(){
    file_i_o();
    vector<int>nums;
	int x;
	while(cin>>x) nums.push_back(x);
	dp = new int[11];
	cout<<permutation(nums, 10)<<endl;
	cout<<permutationTable(nums,10);
	// cout<<combination(nums, nums.size()-1, 10)<<endl;
	// cout<<combinationTable(nums,10);
}