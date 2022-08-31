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

int recc(vector<int>& nums1, vector<int>& nums2, int n, int m){
    if(n==0 or m==0) return 0;
    int cnt;
    if(nums1[n-1] == nums2[m-1]){
        cnt = (recc(nums1,nums2,n-1,m-1) + 1);
    }
    else{
        cnt = max(recc(nums1,nums2,n-1,m), recc(nums1,nums2,n,m-1));
    }
    return cnt;
}

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    return recc(nums1,nums2,n,m);
}


int main(){
    file_i_o();
    cin>>n;
}