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
class pairsBoolean{
public:
    int trueCount = 0, falseCount = 0;
};

void evaluteTrue(pairsBoolean left, pairsBoolean right, pairsBoolean &res, char opr){
    int total = ((left.trueCount + left.falseCount) * (right.trueCount + right.falseCount));
    int totalTrue = 0, totalFalse = 0;
    if(opr == '|'){
        totalFalse = (left.falseCount * right.falseCount);
        totalTrue = total - totalFalse;
    }
    else if(opr == '^'){
        totalTrue = (left.falseCount * right.trueCount) + (left.trueCount * right.falseCount);
        totalFalse = total - totalTrue;
    }
    else if(opr == '&'){
        totalTrue = (left.trueCount * right.trueCount);
        totalFalse = total - totalTrue;
    }
    res.trueCount += totalTrue;
    res.falseCount += totalFalse;
}

pairsBoolean countWays(string &s, int si, int ei){
    if(si==ei){
        pairsBoolean tmp;
        tmp.trueCount = (s[ei] == 'T');
        tmp.falseCount = (s[ei] == 'F');
        return tmp;
    }
    pairsBoolean res;
    for(int cut = si+1; cut<ei; cut+=2){
        pairsBoolean lRes = countWays(s, si, cut-1);
        pairsBoolean rRes = countWays(s, cut+1, ei);

        evaluteTrue(lRes, rRes, res, s[cut]);
    }
    return res;
}

int main(){
    file_i_o();
    pairsBoolean tmp ;
    string s = "T^T^F";
    tmp = countWays(s , 0, size(s)-1);
    cout<<tmp.trueCount;
}