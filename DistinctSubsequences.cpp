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
const static int N = 1e3+2;
int dp[N][N];
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


int recc(string s, string t, int n, int m){
    if(n<m) return 0;
    if(m==0) return 1;

    int cnt;
    if(s[n-1] == t[m-1]){
        cnt = (recc(s,t,n-1,m-1)+recc(s,t,n-1,m));
    }
    else{
        cnt = (recc(s,t,n-1,m));
    }

    return cnt;
}


long memo(string s, string t, int n, int m){
    if(n<m) return dp[n][m] = 0;
    if(m==0) return dp[n][m] = 1;
    if(dp[n][m] != -1) return dp[n][m];
    long cnt;
    if(s[n-1] == t[m-1]){
        cnt = (memo(s,t,n-1,m-1)+memo(s,t,n-1,m));
    }
    else{
        cnt = (memo(s,t,n-1,m));
    }

    return dp[n][m] = cnt;
}

//Note signed integer over flow mod with 1e9+7
long long tabu(string s, string t, int N, int M){
    for(int n=0; n<=N; n++){
        for(int m=0; m<=M; m++){
            if(n<m){
                dp[n][m] = 0;
                continue;
            }
            if(m==0){
                dp[n][m] = 1;
                continue;
            }
            if(s[n-1] == t[m-1]){
                dp[n][m] =  (dp[n-1][m-1]+dp[n-1][m])% 1000000007;
            }
            else{
                dp[n][m] = dp[n-1][m];
            }
        }
    }
    return dp[N][M];
}


int main(){
    file_i_o();
    cin>>n;
}