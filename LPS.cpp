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

int recc(string s, int st, int en){
    if(st>=en) return st == en ? 1 : 0;
    int cnt;
    if(s[st] != s[en]){
        cnt = max(recc(s,st+1,en),recc(s,st,en-1));
    }
    else cnt = (recc(s,st+1,en-1)+2);

    return cnt;
}

int memo(string &s, int st, int en, vector<vector<int>>&dp){
    if(st>=en) return dp[st][en] = (st == en ? 1 : 0);
    if(dp[st][en] != 0) return dp[st][en];
    int cnt;
    if(s[st] != s[en]){
        cnt = max(memo(s,st+1,en,dp),memo(s,st,en-1,dp));
    }
    else cnt = (memo(s,st+1,en-1,dp)+2);

    return dp[st][en] = cnt;
}

int tabu(string s, int ST, int EN,vector<vector<int>>&dp){
    for(int gap=0; gap<s.size();gap++){
        for(int st=0, en = gap; en<s.size();st++,en++){
            if(st>=en) {
                dp[st][en] = st == en ? 1 : 0;
                continue;
            }
            if(s[st] != s[en]){
                dp[st][en] = max(dp[st+1][en],dp[st][en-1]);
            }
            else dp[st][en] = (dp[st+1][en-1]+2);    
        }
    }
    return dp[ST][EN];
}

int longestPalindromeSubseq(string s) {
    vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,0));
    return memo(s,0,s.size()-1,dp);
}


int main(){
    file_i_o();
    string s;
    cin>>s;
    cout<<longestPalindromeSubseq(s);
}