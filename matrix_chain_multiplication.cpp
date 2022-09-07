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

const static int N = 1e4;
int dp[N][N];

int mcm(int arr[], int si, int ei){
    if(ei = si+1) return dp[si][ei] = 0;
    if(dp[si][ei] != 0 ) return dp[si][ei];
    int mini = (int)(1e9);
    for(int cut = si+1; cut<ei; cut++){
        int left = mcm(arr, si, cut);
        int right = mcm(arr, cut, ei);

        mini = min(mini, left + arr[si] * arr[cut] * arr[ei] + right);
    }
    return dp[si][ei] = mini;
}


int main(){
    file_i_o();
    cin>>n;
}