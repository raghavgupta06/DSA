class Solution {
public:
int dp[101][101][2];
int solve(vector<int>& piles,int p,int i, int m,int n){
    if(i>=n){
        return 0;
    }
    if(dp[i][m][p]!=-1){
        return dp[i][m][p];
    }
    int result=(p==1)?-1:INT_MAX;
    int s=0;
    for(int x=1;x<=min(2*m,n-i);x++){
        s+=piles[i+x-1];
        if(p==1){
            result=max(result,s+solve(piles,0,i+x,max(m,x),n));
        }
        else{
            result=min(result,solve(piles,1,i+x,max(m,x),n));
        }
    }
    return dp[i][m][p]=result;
}
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(piles,1,0,1,n);
    }
};