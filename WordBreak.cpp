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

unordered_set<string>st;
int recc(string s, int n, int start){
    if(start==n) return 1;

    int cnt = 0;
    for(int end = start;end<n;end++){
        string curr = s.substr(start,end-start+1);
        if(st.count(curr)){
            cnt += recc(s, n, end+1);
        }
    }
    return cnt;
}

bool wordBreak(string s, vector<string>& wordDict) {
    for(string word:wordDict){
        st.insert(word);
    }
    int n = s.size();
    return recc(s,n,0);        
}

int main(){
    file_i_o();
    cin>>n;
}