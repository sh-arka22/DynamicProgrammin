string printingLPSubsequence(string &s, int si, int ei, vector<vector<int>>&dp){
//     // cout<<s;
//     if(si>=ei) return (si==ei) ? s[si]+"" : "";
    
//     string str;
//     if(s[si] == s[ei]) str = s[si] + printingLPSubsequence(s, si+1, ei-1, dp) + s[ei];
//     else if(dp[si+1][ei] > dp[si][ei]){
//         str =  printingLPSubsequence(s,si+1,ei,dp);
//     }
//     else{
//         str =  printingLPSubsequence(s, si, ei-1,dp);
//     }
//     return str;
// }