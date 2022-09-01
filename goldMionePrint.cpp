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
int dp[N][N];
int recc(int i, int j){
    if(i<0 or i>=n or j<0 or j>=m) return dp[i][j] = 0;

    if(dp[i][j] != -1) return dp[i][j];
    int a = recc(i-1,j+1);
    int b = recc(i,j+1);
    int c = recc(i+1,j+1);

    int total = grid[i][j] + max(a,max(b,c));

    return dp[i][j] = total;
}

/**
 * Here tabulisation and memoisation dp comes same
 * 
 */

int dir[3][2] = {{-1,1},{0,1},{1,1}};
string printPathGoldMine(int sr, int sc, string asf){
    if(sc == m-1){
        asf += "("+ to_string(sr) + ", " + to_string(sc) + ")";
        return asf;
    }
    int maxGold = 0;
    int idx = -1;
    for(int d = 0;d<3;d++){
        int r = sr+dir[d][0], c = sc+dir[d][1];
        if(r<0 or c<0 or r>= n or c>=m) continue;
        if(dp[r][c] > maxGold){
            maxGold = dp[r][c];
            idx = d;
        }
    }
    if(idx != -1){
        int r = sr + dir[idx][0], c = sc+dir[idx][0];
        printPathGoldMine(r,c,asf+"("+ to_string(r) + ", " + to_string(c) + ")");
    }
    return asf;
}


void goldMine(){
    int maxi = 0;
    // int ans = tabu(0,0);
    for(int i=0;i<n;i++){
        maxi = max(maxi, recc(i,0));
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<maxi<<endl;
    cout<<printPathGoldMine(1,0,"");
}

int main(){
    file_i_o();
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=-1;
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