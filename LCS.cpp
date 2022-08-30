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
const static int N = 1e3;
int dp[N][N];
int recc(string s1, string s2, int n, int m){
    if(n == 0 or m == 0){
        return 0;
    }
    int cnt;
    if(s1[n-1] == s2[m-1]){
        cnt = recc(s1, s2, n-1, m-1)+1;
    }
    else {
        cnt = max(recc(s1, s2, n-1, m), recc(s1, s2, n, m-1));
    }
    return cnt;
}

int tabu(string s1, string s2, int N, int M){
    for(int n=0; n<=N; n++){
        for(int m=0; m<=M; m++){
            if(n == 0 or m == 0){
                dp[n][m] = 0;
                continue;
            }
            if(s1[n-1] == s2[m-1]){
                dp[n][m] = dp[n-1][m-1]+1;
            }
            else {
                dp[n][m] = max(dp[n-1][m], dp[n][m-1]);
            }
        }
    }
    return dp[N][M];
}

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    cout<<recc(text1, text2, n,m);
}

int main(){
    file_i_o();
    cin>>n;
}