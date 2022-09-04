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

//********************************************************************************************************************************
const static int N = 1e5;
bool vis[N];
int recc(vector<int>& nums,int idx, int k, int sumSF, int tar){
    if(k==0) return 1; // NOTE
    if(sumSF > tar) return 0; // NOTE
    if(tar == sumSF){
        return recc(nums, 0, k-1, 0, tar); //NOTE
    }
    int res = 0;
    for(int i = idx; i<nums.size();i++){
        if(vis[i]) continue;

        vis[i] = 1;
        res += recc(nums, i+1, k, sumSF+nums[i], tar);
        vis[i] = 0;
    }
    return res;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int n = nums.size(), sum = 0, maxele;

    sum = accumulate(begin(nums), end(nums),0);
    maxele = *max_element(nums.begin(), nums.end());

    if(sum%k != 0 or maxele>sum/k) return 0;   

    return recc(nums, 0, k, 0, sum/k);     
}
//************************************************************************************************
int main(){
    file_i_o();
    cin>>n;
}