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
    cout<<endl;
}
void display2D(vector<vector<int>>dp){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int *LIS;
int *LDS;
int LIS_LR(vector<int>& nums){
    int n = nums.size(), maxLen = 0;

    for(int i=0;i<n;i++){
        LIS[i] = 1;
        for(int j=i-1;j>=0;j--){
            if(nums[i] > nums[j]){
                LIS[i] = max(LIS[i], LIS[j] + 1); 
            }
        }
        maxLen = max(maxLen,LIS[i]);
    }
    return maxLen;
}

int LIS_RL(vector<int>& nums){
    int maxLen = 0;
    int n = nums.size();
    for(int i=n-1;i>=0;i--){
        LDS[i] = 1;
        for(int j=i+1;j<n;j++){
            if(nums[i]>nums[j]){
                LDS[i] = max(LDS[i], LDS[j] + 1);
            }
        }
        maxLen = max(maxLen, LDS[i]);
    }
    return maxLen;
}


int LongestBitonicSequence(vector<int>nums){
    n = nums.size();
    LIS = new int[n];
    LDS = new int[n];
    int lis = LIS_LR(nums);
    int lds = LIS_RL(nums);
    int maxLen = 0;
    for(int i=0;i<n;i++){
        maxLen = max(maxLen, LDS[i]+LIS[i]-1);
    }
    return maxLen;
}
int main(){
    file_i_o();
    int x;
    vector<int>nums;
    while(cin>>x) nums.push_back(x);
    cout<<LongestBitonicSequence(nums)<<endl;
    display1D(LIS);
    display1D(LDS);
    // cin>>n;
}