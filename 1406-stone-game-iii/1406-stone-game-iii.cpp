class Solution {
public:
int dp[50001];
int solve(vector<int>& stoneValue,int i,int n){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int result=stoneValue[i]-solve(stoneValue,i+1,n);
    if(i+1<n)
    result=max(result,stoneValue[i]+stoneValue[i+1]-solve(stoneValue,i+2,n));
    if(i+2<n)
    result=max(result,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-solve(stoneValue,i+3,n));
    return dp[i]=result;
   
}
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        memset(dp,-1,sizeof(dp));
        int diff=solve(stoneValue,0,n);
        if(diff>0){
            return "Alice";
        }
        else if(diff==0){
            return "Tie";
        }
            return "Bob";
    }
};