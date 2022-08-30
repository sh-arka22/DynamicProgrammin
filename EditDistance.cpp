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

int recc(string &s1, string &s2, int n, int m){
    if(n==0 or m==0){
        return (n==0?m:n);
    }
    int cnt;
    if(s1[n-1]==s2[m-1]){
        cnt = recc(s1, s2, n-1, m-1);
    }
    else{
        cnt = min(recc(s1,s2,n,m-1),(min(recc(s1,s2,n-1,m), recc(s1,s2,n-1,m-1))));
        //        insert               delete                   replace
        cnt+=1;
    }
    return cnt;
}

//minmiizing with diff cost iunsertion deletion and replace 
//cost a-insert    b-delete     c-replce
int a = 1, b = 1, c = 1; // if i was given insertin deltion and insertion cost
int recc(string &s1, string &s2, int n, int m){

    if(n==0 or m==0){
        return dp[n][m] = (n==0 ? m *a  : n*b);
    }
    
    if(dp[n][m] != -1) return dp[n][m];
    
    int cnt;
    if(s1[n-1]==s2[m-1]){
        cnt = recc(s1, s2, n-1, m-1);
    }
    else{
        cnt = min(recc(s1,s2,n,m-1)+a,(min(recc(s1,s2,n-1,m)+b, recc(s1,s2,n-1,m-1)+c)));
        //        insert               delete                   replace
        // cnt+=1;
    }
    return dp[n][m] = cnt;
}



const static int N = 1e3+1;
long dp[N][N];
int recc(string &s1, string &s2, int n, int m){

    if(n==0 or m==0){
        return dp[n][m] = (n==0?m:n);
    }
    
    if(dp[n][m] != -1) return dp[n][m];
    
    int cnt;
    if(s1[n-1]==s2[m-1]){
        cnt = recc(s1, s2, n-1, m-1);
    }
    else{
        cnt = min(recc(s1,s2,n,m-1),(min(recc(s1,s2,n-1,m), recc(s1,s2,n-1,m-1))));
        //        insert               delete                   replace
        cnt+=1;
    }
    return dp[n][m] = cnt;
}


int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    int ans = recc(word1,word2,n,m);        
}

int main(){
    file_i_o();
    cin>>n;
}