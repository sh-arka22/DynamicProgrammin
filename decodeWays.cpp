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

int *dp;
int recc(string s, int idx){
    if(s[idx] == '0') return dp[idx] = 0;
    if(idx == 0) return dp[idx] = 1;
    
    if(dp[idx] != -1) return dp[idx];

    char ch1 = s[idx-1];
    int cnt = recc(s, idx-1);
    
    if(idx>=2){
        char ch2 = s[idx-2];
        int num = (ch2-'0')*10 + (ch1-'0');
        if(num<=26 and num>0)
            cnt+=recc(s,idx-2);
    }
    return dp[idx] = cnt;
}

int tabulation(string s, int IDX){
    for(int idx=0; idx<=IDX; idx++){
        if(s[idx] == '0'){
            dp[idx] = 0;
            continue;
        }
        if(idx == 0){
            dp[idx] = 1;
            continue;
        }
        
        // if(dp[idx] != -1) return dp[idx];
        char ch1 = s[idx-1];
        int cnt = dp[idx-1];
        
        if(idx>=2){
            char ch2 = s[idx-2];
            int num = (ch2-'0')*10 + (ch1-'0');
            if(num<=26 and num>0)
                cnt+=dp[idx-2];
        }
        dp[idx] = cnt;
    }
    return dp[IDX];
}

int numDecodings(string s) {
    int n = s.size();
    dp = new int[n+1];
    fill(dp,dp+n+1, -1);
    int ans = recc(s,n);
    delete[] dp;
    return ans;
}

int main(){
    file_i_o();
    cout<<numDecodings("123");
    cin>>n;
}