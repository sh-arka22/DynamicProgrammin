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
const int N = 1003;
int grid[N][N];
int dp2[N][N];
int recc(int i, int j){
    if(i<0 or i>=n or j<0 or j>=m) return dp2[i][j] = 0;

    if(dp2[i][j] != -1) return dp2[i][j];
    int a = recc(i-1,j+1);
    int b = recc(i,j+1);
    int c = recc(i+1,j+1);

    int total = grid[i][j] + max(a,max(b,c));

    return dp2[i][j] = total;
}

void goldMine(){
    int maxi = 0;
    for(int i=0;i<n;i++){
        maxi = max(maxi, recc(i,0));
    }
    cout<<maxi<<endl;
}

int main(){
    file_i_o();
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp2[i][j]=-1;
        }
    }
    int x;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>x;
            grid[i][j] = x;
        }
    }
    goldMine();
}