// Problem Link -  https://www.geeksforgeeks.org/minimum-maximum-values-expression/
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

pair<int, int> evaluateMinMax(pair<int, int>left, pair<int, int>right, char operator_){
    pair<int, int> myRes;
    if(operator_=='+'){
        myRes.first = left.first + right.first; //adding minimum + minimum
        myRes.second = left.second + right.second; // adding maximum + maximum
    }
    else if(operator_=='*'){
        myRes.first = left.first * right.first; //adding minimum * minimum
        myRes.second = left.second * right.second; // adding maximum * maximum
    }
    return myRes;
}

pair<int, int> minMax(string str, int si, int ei, vector<vector<pair<int, int>>>&dp){
    if(si == str.size()-1) {
        cout<<str[si]<<endl;
        return dp[si][ei] = {str[si]-'0', str[si]-'0'};
    }
    if(dp[si][ei].first != -1 and dp[si][ei].second != -1)
        return dp[si][ei];
    pair<int, int> myRes = {(int)1e9, 0};
    for(int cut = si; cut< ei; cut+=2){
        pair<int, int> left = minMax(str, si, cut-1, dp);
        pair<int, int> right = minMax(str, cut+1, ei, dp);
        pair<int, int> pair_ = evaluateMinMax(left, right, str[cut]);

        myRes.first = min(myRes.first, pair_.first);
        myRes.second = max(myRes.second, pair_.second);
    }
    cout<<dp[si][ei].first<<" "<<dp[si][ei].second<<" "<<myRes.first<<" "<<myRes.second<<endl;
    return dp[si][ei] = myRes;
}

void call(){
    string str;

    str = "1+2*3+4*5";
    int n = str.size();
    vector<vector<pair<int, int>>>dp(n, vector<pair<int, int>>(n, {-1,-1}));
    pair<int, int> ans = minMax(str, 0, n-1, dp);
    cout<<"min="<<ans.first<<" "<<"max"<<ans.second;
}

int main(){
    file_i_o();
    call();
}