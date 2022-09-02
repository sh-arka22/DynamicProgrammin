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

int *LEN;
int *CNT;

int  count(vector<int>& nums){
    int maxLen = 0, maxCount = 0;
    for(int i=0;i<nums.size();i++){
        LEN[i] = 1;
        CNT[i] = 1;
        for(int j = i-1;j>=0;j--){
            if(nums[i] > nums[j]){
                if(LEN[i] < LEN[j]+1){
                    LEN[i] = LEN[j]+1;
                    CNT[i] = CNT[j];
                }
                else if(LEN[i] == LEN[j]+1){
                    CNT[i] += CNT[j];
                }
            }
        }
        if(LEN[i] > maxLen){
            maxLen = LEN[i];
            maxCount = CNT[i];
        }
        else if(LEN[i] == maxLen){
            maxCount += CNT[i];
        }
    }
    return maxCount;
}


int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    LEN = new int[n];
    CNT = new int[n];
    return count(nums);
}

int main(){
    file_i_o();
    cin>>n;
}