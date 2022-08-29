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


int mod = 1e9+7;
long recc(string s, int idx){
    if(s[idx]=='0') return 0;
    if(idx == s.size()) return 1;
    char ch1 = s[idx];

    long cnt = 0;

    if(ch1 == '*'){
        cnt += 9*recc(s,idx+1)%mod; //comes as single char
        if(idx < n-1){
            char ch2 = s[idx+1];
            if(ch2>='0' and ch2<='6'){
                cnt += 2*recc(s,idx+2)%mod;
            }
            else if(ch2 >= '7' and ch2<='9'){
                cnt += 1*recc(s,idx+2)%mod;
            }
            else{
                cnt += 15 * recc(s,idx+2)%mod;
            }
        }
        else{
            //nothing
        }
    }
    else{
        /**
         * starting character is not a star
         */
        cnt += 1 * (recc(s,idx+1))%mod;
        if(idx < n-1){
            char ch2 = s[idx+1];
            if(ch2 == '*'){
                if(ch1 == '1') cnt += 9 * recc(s,idx+2)%mod;
                else if(ch1 == '2') cnt += 6 * recc(s,idx+2)%mod;
            }
            else if(ch2 != '*'){
                int num = (ch1-'0')*10 + (ch2-'0');
                if(num<=26 and num>0){
                    cnt+= 1*recc(s,idx+2)%mod;
                }
            }
        }
    }
    return cnt;
}



int main(){
    file_i_o();
    cin>>n;
}