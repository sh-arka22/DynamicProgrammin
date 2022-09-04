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

int dirs[8][2] = {{-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}};
//******************************* TABULISATION *******************************
double knightProbability(int N, int K, int r, int c) {
    vector<vector<double>> m(N, vector<double>(N, 1));
    while (K-- > 0) {
        vector<vector<double>> next(N, vector<double>(N, 0));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (auto &dir : dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    if (x < 0 || x >= N || y < 0 || y >= N) continue;
                    next[i][j] += m[x][y];
                }
                next[i][j] /= 8;
            }
        }
        m = next;
    }
    return m[r][c];
}

//******************************* RECC *******************************
int dirs[8][2] = {{-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}};
double recc(int n, int k, int row, int col){
    if(k==0) return 1.0;
    double cnt = 0;
    for(auto &[dr,dc]: dirs){
        int r = row+dr, c = col+dc;
        if(r>=0 and c>=0 and r<n and c<n)
            cnt += recc(n, k-1, r, c);
    }
    return cnt/8.0;
}
//****************************** TABULISATION  ********************************
int dirs[8][2] = {{-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}};
vector<vector<vector<double>>>dp;
double recc(int n, int k, int row, int col){
    if(k==0) return dp[k][row][col] = 1.0;
    if(dp[k][row][col] != 0.0) return dp[k][row][col];
    double cnt = 0;
    for(auto &[dr,dc]: dirs){
        int r = row+dr, c = col+dc;
        if(r>=0 and c>=0 and r<n and c<n)
            cnt += recc(n, k-1, r, c);
    }
    return dp[k][row][col] = cnt/8.0;
}




double knightProbability(int n, int k, int row, int column) {
    dp.resize(k+1, vector<vector<double>>(n+1, vector<double>(n+1, 0.0)));
    return recc(n, k, row, column);
}

int main(){
    file_i_o();
    cin>>n;
}